/* bfprof.c -- BrainFuck Profiler
**
** Written by Robert Quattlebaum Jr. <darco@deepdarc.com>
**
** This interpreter assumes no-change on EOF.
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

//#define PRINT_BFOPS_AT_EXIT		(1)

#define MAX_PROG_SIZE			(65536)
#define MAX_DATA_SIZE			(65536)
#define MAX_DEPTH				(1024)

#define ERROR_FILE				(-1)
#define ERROR_BAD_ARG				(-8)
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
	int pass_count[65535]={0};
	short data[65535]={0};
	int stack[1024]={0};
	int depth=0;			// Depth tracker
	int pc=0;				// Program counter
	int di=0;				// data index
	unsigned long long tic=0;		// Total number of instructions executed
	int time_start=0;		// value of clock() at start of execution
	int data_mask=0xFFFFFFFF;
	int output_optimized_code=0;
	int i,file_count=0;
	
	/*
 --	** -- P R O C E S S   A R G U M E N T S -------------------------------------------------------
	*/
	
/*
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
*/

	for(i=1;i<argc;i++)
	{
		if(argv[i][0]=='-' && argv[i][1]=='-')
		{
			if(strcmp(argv[i]+2,"16-bit")==0)
			{
				data_mask=0x0000FFFF;
			}
			else
			if(strcmp(argv[i]+2,"8-bit")==0)
			{
				data_mask=0x000000FF;
			}
			else
			if(strcmp(argv[i]+2,"7-bit")==0)
			{
				data_mask=0x0000007F;
			}
			else
			if(strcmp(argv[i]+2,"print-bfops")==0)
			{
				//print_bfops_at_exit=1;
			}
		}
		else if(argv[i][0]=='-')
		{
			int j;
			int ii=i;
			for(j=1;j && argv[ii][j];j++)
			{
				switch(argv[ii][j])
				{
					case 'O':
						output_optimized_code=1;
						break;
					case '8':
						data_mask=0x000000FF;
						break;
					case '7':
						data_mask=0x0000007F;
						break;
					case 'c':
						//bf2c_mode=1;
						break;
					case 'o':
						if(argv[i+1])
						{
							out=fopen(argv[i+1],"w");
							if(!out)
							{
								fprintf(stderr,"error: Unable to open \"%s\" for write access\n",argv[3]);
								return ERROR_FILE;		
							}
							i++;
						}
						else
						{
							fprintf(stderr,"error: Missing argument to '-%c'\n",argv[ii][j]);
							return ERROR_BAD_ARG;
						}
						break;
					default:
						fprintf(stderr,"error: Unknown argument '%c'\n",argv[ii][j]);
						return ERROR_BAD_ARG;
						break;
				}
			}
		}
		else
		{
			if(file_count==0)
			{
				progin=fopen(argv[i],"r");
				if(!progin)
				{
					fprintf(stderr,"error: Unable to open \"%s\" for read access\n",argv[i]);
					return ERROR_FILE;		
				}
			}
			else
			if(file_count==1)
			{
				in=fopen(argv[i],"r");
				if(!in)
				{
					fprintf(stderr,"error: Unable to open \"%s\" for read access\n",argv[i]);
					return ERROR_FILE;		
				}
			}
			else
			if(file_count==2)
			{
				out=fopen(argv[i],"w");
				if(!out)
				{
					fprintf(stderr,"error: Unable to open \"%s\" for write access\n",argv[i]);
					return ERROR_FILE;		
				}
			}
			else
			{
				fprintf(stderr,"error: I don't know what to do with \"%s\"\n",argv[i]);
				return ERROR_BAD_ARG;
			}
			
			file_count++;
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
				pc++;
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

	if(!output_optimized_code)
		fprintf(stdout,"<html><body><h1>output</h1><pre style='font-size: -1; background-color: black; color: #CCC;'>\n");
	
	while(prog[pc])
	{
		pass_count[pc]++;
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
				if(!output_optimized_code)
				{
					char c = data[di];
					if(c == '<') {
						fprintf(out,"&lt;");
					} else if(c == '&') {
						fprintf(out,"&amp;");
					} else if(c && c != '\r') {
						fputc(data[di],out);
					}
					fflush(out);
				}
				break;
				
			case '[':
				if(!data[di])
				{
					pass_count[pc]--;
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
			default:
				tic--;
		}
		pc++;
		tic++;
	}

	
#ifdef PRINT_BFOPS_AT_EXIT	
	PRINT_DEBUG_INFO();

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

	// Print out profile in HTML form
	if(!output_optimized_code)
	{
	int line_no=0;
	fprintf(stdout,"</pre><hr /><h1>profiled code</h1><tt>\n");
				fprintf(stdout,"<br />\n<b>%04d: </b>",++line_no);
	int last_amount=-1;
	for(pc=0;prog[pc];pc++)
	{
		double activ=1.4*sqrt(sqrt(
				sqrt(
					(double)pass_count[pc]/(double)tic
				))
			);
		if(activ>1.0)
			activ=1.0;
		unsigned char amount=((unsigned char)(activ*0xF));
		switch(prog[pc])
		{
			case '\n':
				fprintf(stdout,"<br />\n<b>%04d: </b>",++line_no);
				break;
			case ' ':
				if(!pc || prog[pc-1]==' '|| prog[pc-1]=='\n'|| prog[pc-1]=='\t')
					fprintf(stdout,"&nbsp;");
				else
					fprintf(stdout," ");
				break;
			case '\t':
				fprintf(stdout,"&nbsp;&nbsp;&nbsp;&nbsp;");
				break;
			case '>':
			case '<':
			case '+':
			case '-':
			case '[': 
			case ']':
			case '.':
			case ',':
				if(pass_count[pc]!=0)
				{
					if(amount!=last_amount)
					{
						if(last_amount!=-1)
							fprintf(stdout,"</font>");
						fprintf(stdout,"<font color='#%01X0%01X000'>",amount,0xF-amount);
					}
					if(prog[pc]=='>')
						fprintf(stdout,"&gt;");
					else
					if(prog[pc]=='<')
						fprintf(stdout,"&lt;");
					else
						fprintf(stdout,"%c", prog[pc]);
					last_amount=amount;
					break;
				}
			case 0:
			case -1:
				break;
			default:
				amount=-1;
				if(amount!=last_amount)
				{
					if(last_amount!=-1)
						fprintf(stdout,"</font>");
				}
				fprintf(stdout,"%c", prog[pc]);
				last_amount=amount;
				break;
		}
	}
	if(last_amount!=-1)
		fprintf(stdout,"</font>");
	fprintf(stdout,"</body</html>\n");
	}
	else
	for(pc=0;prog[pc];pc++)
	{
		if(pass_count[pc])
			fprintf(stdout,"%c",prog[pc]);
	}
	
	// Return value under data pointer
	return data[di];
}
