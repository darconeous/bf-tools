/* sbfi.c -- Simple Reference BrainFuck Interpreter
**
** Written by Robert Quattlebaum Jr. <darco@deepdarc.com>
** This program can be considered PUBLIC DOMAIN.
**
** This interpreter assumes no-change on EOF.
*/

#include <stdio.h>
#include <time.h>

#define PRINT_BFOPS_AT_EXIT		(1)

#define MAX_PROG_SIZE			(65536)
#define MAX_DATA_SIZE			(65536)
#define MAX_DEPTH				(1024)

#define ERROR_FILE				(-1)
#define ERROR_UNSYMETRIC		(-2)
#define ERROR_PROG_TOO_BIG		(-3)
#define ERROR_UNMATCHED_LOOP	(-4)
#define ERROR_DATA_OVERFLOW		(-5)
#define ERROR_DATA_UNDERFLOW	(-6)
#define ERROR_STACK_OVERFLOW	(-7)

#define PRINT_DEBUG_INFO()	fprintf(stderr,"debug: pc=%04u di=%04u depth=%04u tic=%llu\n",pc, di, depth, tic)

int
main(int argc, char* argv[])
{
	FILE* progin=stdin;
	FILE* in=stdin;
	FILE* out=stdout;
	char prog[65535]={0};
	int data[65535]={0};
	int stack[1024]={0};
	int depth=0;			// Depth tracker
	int pc=0;				// Program counter
	int di=0;				// data index
	unsigned long long tic=0;		// Total number of instructions executed
	int time_start=0;		// value of clock() at start of execution
	
	/*
 --	** -- P R O C E S S   A R G U M E N T S -------------------------------------------------------
	*/
	
	// Program file
	if(argc>1)
	{
		progin=fopen(argv[1],"r");
		if(!progin)
		{
			fprintf(stderr,"error: Unable to open \"%s\" for read access\n",argv[1]);
			return ERROR_FILE;		
		}
	}

	// Input file
	if(argc>2)
	{
		in=fopen(argv[2],"r");
		if(!in)
		{
			fprintf(stderr,"error: Unable to open \"%s\" for read access\n",argv[2]);
			return ERROR_FILE;		
		}
	}

	// Output file
	if(argc>3)
	{
		out=fopen(argv[3],"w");
		if(!out)
		{
			fprintf(stderr,"error: Unable to open \"%s\" for write access\n",argv[3]);
			return ERROR_FILE;		
		}
	}
		
	/*
 --	** -- P R O G R A M   L O A D -----------------------------------------------------------------
	*/
		
	while( pc<MAX_PROG_SIZE-1 && (prog[pc]=fgetc(progin)) != EOF)
	{
		switch(prog[pc])
		{
			case '+':
			case '-':
			case '>':
			case '<':
			case '.':
			case ',':
				pc++;
				break;
			
			case '[':
				depth++;
				pc++;
				break;
			
			case ']':
				depth--;
				pc++;
				break;
				
			default:
				// Strip comments
				break;
		}
	}
	
	if(prog[pc]!=EOF)
	{
		fprintf(stderr,"error: Program too big! (Max instructions: %d)\n",MAX_PROG_SIZE-1);
		return ERROR_PROG_TOO_BIG;
	}
	
	if(depth)
	{
		if(depth>0)
			fprintf(stderr,"error: %d unmatched '[' commands in program\n",depth);
		else
			fprintf(stderr,"error: %d unmatched ']' commands in program\n",-depth);
		return ERROR_UNSYMETRIC;
	}
	
	prog[++pc]=0;
	pc=0;
	depth=0;
	
	/*
 --	** -- P R O G R A M   E X E C U T I O N -------------------------------------------------------
	*/
	
	time_start=clock();

	while(prog[pc])
	{
		switch(prog[pc])
		{
			case '+':
				data[di]++;
				break;
				
			case '-':
				data[di]--;
				break;

			case '>':
				if(di>=MAX_DATA_SIZE-1)
				{
					fprintf(stderr,"error: Data pointer overflow\n");
					PRINT_DEBUG_INFO();
					return ERROR_DATA_OVERFLOW;
				}
				di++;
				break;
				
			case '<':
				if(di==0)
				{
					fprintf(stderr,"error: Data pointer underflow\n");
					PRINT_DEBUG_INFO();
					return ERROR_DATA_UNDERFLOW;
				}
				di--;
				break;
				
			case ',':
				{
					const int val=fgetc(in);
					
					// No change on EOF
					if(val!=EOF)
						data[di]=val;
				}
				break;
				
			case '.':
				fputc(data[di],out);
				fflush(out);
				break;
				
			case '[':
				if(!data[di])
				{
					int nd=1;
					do {
						pc++;
						if(prog[pc]=='[')
							nd++;
						else if(prog[pc]==']')
							nd--;
					} while(nd);
				}
				else
				{
					if(depth>=MAX_DEPTH)
					{
						fprintf(stderr,"error: Stack overflow. Max supported \"[]\" depth is %d.\n",MAX_DEPTH);
						PRINT_DEBUG_INFO();
						return ERROR_STACK_OVERFLOW;
					}
					
					stack[depth++]=pc;
				}
				break;
				
			case ']':
				if(depth==0)
				{
					fprintf(stderr,"error: unmatched ']'\n");
					PRINT_DEBUG_INFO();
					return ERROR_UNMATCHED_LOOP;
				}
				pc=stack[--depth]-1;
				break;
		}
		pc++;
		tic++;
	}

	
#ifdef PRINT_BFOPS_AT_EXIT	
	PRINT_DEBUG_INFO();

	fprintf(stderr,"debug: data[di]=%d\n",data[di]);

	{
		double bfops=(double)tic/(double)(clock()-time_start)*(double)CLOCKS_PER_SEC;

		if(bfops<1000.0)
			fprintf(stderr,"debug: exec_speed=%.1f bfops\n",bfops);
		else if(bfops<1000000.0)
			fprintf(stderr,"debug: exec_speed=%.1fK bfops\n",bfops/1000.0);
		else if(bfops<1000000000.0)
			fprintf(stderr,"debug: exec_speed=%.1fM bfops\n",bfops/1000000.0);
		else 
			fprintf(stderr,"debug: exec_speed=%.1fG bfops\n",bfops/1000000000.0);
	}
#endif

	// Return value under data pointer
	return data[di];
}