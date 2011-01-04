/* bf.c -- Optimizing BrainFuck Interpreter
**
** Written by Robert Quattlebaum Jr. <darco@deepdarc.com>
**
** This program is licensed under the terms of the GNU GPL.
** See http://www.fsf.org/ for more details.
**
** This interpreter assumes no-change on EOF.
*/

#include <stdio.h>
#include <time.h>
#include <string.h>

#define PRINT_BFOPS_AT_EXIT		(1)
//#define DISABLE_OPTIMIZATION	(1)

//#define DEFAULT_MASK			(0x000000FF)	// 8-bit
//#define DEFAULT_MASK			(0x0000FFFF)	// 16-bit
#define DEFAULT_MASK			(0xFFFFFFFF)	// 32-bit

#define MAX_PROG_SIZE			(65536*8)
#define MAX_DATA_SIZE			(65536*8)
#define MAX_DEPTH				(1024)

#define ERROR_FILE				(-1)
#define ERROR_UNSYMETRIC		(-2)
#define ERROR_PROG_TOO_BIG		(-3)
#define ERROR_UNMATCHED_LOOP	(-4)
#define ERROR_DATA_OVERFLOW		(-5)
#define ERROR_DATA_UNDERFLOW	(-6)
#define ERROR_STACK_OVERFLOW	(-7)
#define ERROR_HELP				(-8)
#define ERROR_BAD_ARG			(-9)

#define PRINT_DEBUG_INFO()	fprintf(stderr,"debug: pc=%04u di=%04u depth=%04u tic=%llu\n",pc, di, depth, tic)

#define INST_SET_CONST				'Z'		// [-]
#define INST_SEEK_NZERO			'S'		// [>] OR [<]
#define INST_ADD_DATA			'A'		// [<+>-] OR [-<+>]

#define INST_INC_PTR			'+'
#define INST_INC_DATA			'>'
#define INST_SLEEP				's'

#define	SLEEP_MULTIPLIER		(sleep_multiplier)

/* TYPES */

typedef struct bfop
{
	char op;
	int count;
	int arg2;
} bfop;

/* GLOBALS */

unsigned int data_mask=DEFAULT_MASK;
int print_bfops_at_exit=0;
double sleep_multiplier=0.05;
#define NO_CHANGE_ON_EOF	(1<<30)
int eof_character = NO_CHANGE_ON_EOF;

/* FUNCTIONS */

// Optimize a given set of BF operations
int optimize(bfop* begin, bfop* end)
{
#define OPT_TABLE_WIDTH		(1024*8)
#define SLEEP_BIT			(1<<30)
#define SET_BIT				(1<<29)
	bfop* iter;
	int balance=0;
	int m=0;
	int _table[OPT_TABLE_WIDTH]={0};
	int* table=_table+OPT_TABLE_WIDTH/2;
	int i;
	int stages=0;
	int sleep_flag=0;
	
	if(end-begin==3 && begin[1].op=='>')
	{
		begin->op=INST_SEEK_NZERO;
		begin->count=begin[1].count;
		end--;
		return end-begin;
	}

	for(iter=begin+1;iter!=end-1;iter++)
	{
		if(!(iter->op=='+' || iter->op=='>' || iter->op==INST_SET_CONST))
			return 0;
		if(iter->op==INST_SET_CONST)
		{
			sleep_flag=1;
		}
		if(iter->op=='>')
			balance+=iter->count;
	}

	if(balance)
		return 0;
	
	for(iter=begin+1;iter<end-1;iter++)
	{
		if(iter->op=='+')
			table[m]+=iter->count;
			
		if(iter->op==INST_SET_CONST && (iter+1)->op==INST_SET_CONST && (iter+1)->count==0)
		{
			table[m]=abs(iter->count)|SLEEP_BIT;
			sleep_flag=0;
			iter++;
		}
		else
		if(iter->op==INST_SET_CONST)
		{
			table[m]=abs(iter->count)|SET_BIT;
		}	
		if(iter->op=='>')
			m+=iter->count;
	}
	
	if(sleep_flag)
	{
		return 0;
	}
		
	iter=begin;
	if(abs(table[0])!=1)
		return 0;
	for(i=0;i<OPT_TABLE_WIDTH;i++)
	{
		if(!_table[i] || i==OPT_TABLE_WIDTH/2)
			continue;
		if(_table[i]>0&&(_table[i]&SLEEP_BIT))
		{
			iter->op=INST_SLEEP;
			iter->count=_table[i]&(~SLEEP_BIT);
			iter->arg2=i-OPT_TABLE_WIDTH/2;
		}
		else
		if(_table[i]>0&&(_table[i]&SET_BIT))
		{
			iter->op=INST_SET_CONST;
			iter->count=_table[i]&(~SET_BIT);
			iter->arg2=i-OPT_TABLE_WIDTH/2;
		}
		else
		{
			iter->op=INST_ADD_DATA;
			iter->count=_table[i];
			iter->arg2=i-OPT_TABLE_WIDTH/2;
		}
		iter++;
		stages++;
	}
	iter->op=INST_SET_CONST;
	iter->count=0;
	iter->arg2=0;
	iter++;
	return end-iter;
}

int execute(bfop* begin, bfop* end, FILE* in, FILE* out)
{
	unsigned int data[65535]={0};
	unsigned int stack[1024]={0};
//	unsigned int data_mask=DEFAULT_MASK;
	unsigned int depth=0;			// Depth tracker
	unsigned int pc=0;				// Program counter
	unsigned int di=0;				// data index
	bfop* prog=begin;
	int time_start=0;		// value of clock() at start of execution
	unsigned long long tic=0;		// Total number of instructions executed
	
	time_start=clock();

	while(prog[pc].op)
	{
		switch(prog[pc].op)
		{
			case INST_SET_CONST:
				tic+=data[di]*3+prog[pc].count;

				data[di+prog[pc].arg2]=prog[pc].count;
				break;

			case INST_SLEEP:
				tic+=prog[pc].count*data[di];
				{
					const int c=clock();
					usleep((int)(prog[pc].count*data[di]*SLEEP_MULTIPLIER));
					time_start+=clock()-c;
				}
				data[di+prog[pc].arg2]=0;

				break;

			case INST_SEEK_NZERO:
				while(data[di])
				{
					if(di>=MAX_DATA_SIZE-(prog[pc].count))
					{
						fprintf(stderr,"error: Data pointer overflow (prog[pc].count=%d)\n",prog[pc].count);
						PRINT_DEBUG_INFO();
						return ERROR_DATA_OVERFLOW;
					}
					else
					if((signed)di<-prog[pc].count)
					{
						fprintf(stderr,"error: Data pointer underflow on INST_SEEK_NZERO (prog[pc].count=%d)\n",prog[pc].count);
						PRINT_DEBUG_INFO();
						return ERROR_DATA_UNDERFLOW;
					}
					di+=prog[pc].count;
					tic+=2+abs(prog[pc].count);
				}

				break;

			case INST_ADD_DATA:
				if(di>=MAX_DATA_SIZE-(prog[pc].arg2))
				{
					fprintf(stderr,"error: Data pointer overflow\n");
					PRINT_DEBUG_INFO();
					return ERROR_DATA_OVERFLOW;
				}
				else
				if((signed)di<-prog[pc].arg2)
				{
					pc++;
					continue;
					
					fprintf(stderr,"error: Data pointer underflow on INST_ADD_DATA\n");
					PRINT_DEBUG_INFO();
					return ERROR_DATA_UNDERFLOW;
				}
				
				tic+=data[di]*((abs(prog[pc].arg2))*2+1+abs(prog[pc].count));

				data[di+prog[pc].arg2]+=data[di]*(prog[pc].count);
				break;

			case '+':
				data[di]+=prog[pc].count;
				tic+=abs(prog[pc].count)-1;
				break;
				
			case '>':
				if(di>=MAX_DATA_SIZE-(prog[pc].count))
				{
					fprintf(stderr,"error: Data pointer overflow (prog[pc].count=%d)\n",prog[pc].count);
					PRINT_DEBUG_INFO();
					return ERROR_DATA_OVERFLOW;
				}
				else
				if((signed)di<-prog[pc].count)
				{
					fprintf(stderr,"error: Data pointer underflow on '>' (prog[pc].count=%d)\n",prog[pc].count);
					PRINT_DEBUG_INFO();
					return ERROR_DATA_UNDERFLOW;
				}
				di+=prog[pc].count;
				tic+=abs(prog[pc].count)-1;
				break;

			case ',':
				{
					const int c=clock();
					const int val=fgetc(in);
					time_start+=clock()-c;
					
					if(val!=EOF) {
						data[di]=val;
					} else {
						if(eof_character != NO_CHANGE_ON_EOF)
							data[di]=eof_character;

						// No change on EOF
						// If out input wasn't stdin already, go ahead and start using stdin.
						if(in!=stdin)
							in = stdin;
					}
				}
				break;
				
			case '.':
				fputc(data[di],out);
				fflush(out);
				break;
				
			case '[':
				if(!(data[di]&data_mask))
					pc=prog[pc].arg2;
				break;
				
			case ']':
				if(data[di]&data_mask)
				{
					pc=prog[pc].arg2;
					tic++;
				}
				break;
		}
		pc++;
		tic++;
	}

	
	if(print_bfops_at_exit)
	{
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
	}

	// Return value under data pointer
	return data[di];
}

int execute_fast(bfop* begin, bfop* end, FILE* in, FILE* out)
{
	unsigned int data[65535]={0};
	unsigned int stack[1024]={0};
	unsigned int depth=0;			// Depth tracker
	unsigned int pc=0;				// Program counter
	unsigned int di=0;				// data index
	bfop* prog=begin;

	while(prog[pc].op)
	{
		switch(prog[pc].op)
		{
			case INST_SET_CONST:
				data[di+prog[pc].arg2]=prog[pc].count;
				break;

			case INST_SLEEP:
				{
					const int c=clock();
					usleep((int)(prog[pc].count*data[di]*SLEEP_MULTIPLIER));
				}
				data[di+prog[pc].arg2]=0;

				break;

			case INST_SEEK_NZERO:
				while(data[di])
				{
					if(di>=MAX_DATA_SIZE-(prog[pc].count))
					{
						fprintf(stderr,"error: Data pointer overflow (prog[pc].count=%d)\n",prog[pc].count);
						return ERROR_DATA_OVERFLOW;
					}
					else
					if((signed)di<-prog[pc].count)
					{
						fprintf(stderr,"error: Data pointer underflow on INST_SEEK_NZERO (prog[pc].count=%d)\n",prog[pc].count);
						return ERROR_DATA_UNDERFLOW;
					}
					di+=prog[pc].count;
				}

				break;

			case INST_ADD_DATA:
				if(di>=MAX_DATA_SIZE-(prog[pc].arg2))
				{
					fprintf(stderr,"error: Data pointer overflow\n");
					return ERROR_DATA_OVERFLOW;
				}
				else
				if((signed)di<-prog[pc].arg2)
				{
					pc++;
					continue;
					
					fprintf(stderr,"error: Data pointer underflow on INST_ADD_DATA\n");
					return ERROR_DATA_UNDERFLOW;
				}
				
				data[di+prog[pc].arg2]+=data[di]*(prog[pc].count);
				break;

			case '+':
				data[di]+=prog[pc].count;
				break;
				
			case '>':
				if(di>=MAX_DATA_SIZE-(prog[pc].count))
				{
					fprintf(stderr,"error: Data pointer overflow (prog[pc].count=%d)\n",prog[pc].count);
					return ERROR_DATA_OVERFLOW;
				}
				else
				if((signed)di<-prog[pc].count)
				{
					fprintf(stderr,"error: Data pointer underflow on '>' (prog[pc].count=%d)\n",prog[pc].count);
					return ERROR_DATA_UNDERFLOW;
				}
				di+=prog[pc].count;
				break;

			case ',':
				{
					const int val=fgetc(in);
					
					if(val!=EOF) {
						data[di]=val;
					} else {
						if(eof_character != NO_CHANGE_ON_EOF)
							data[di]=eof_character;

						// No change on EOF
						// If out input wasn't stdin already, go ahead and start using stdin.
						if(in!=stdin)
							in = stdin;
					}
				}
				break;
				
			case '.':
				fputc(data[di],out);
				fflush(out);
				break;
				
			case '[':
				if(!(data[di]&data_mask))
					pc=prog[pc].arg2;
				break;
				
			case ']':
				if(data[di]&data_mask)
				{
					pc=prog[pc].arg2;
				}
				break;
		}
		pc++;
	}

	// Return value under data pointer
	return data[di];
}

void convert2c(bfop* begin, bfop* end, FILE* out)
{
	bfop* prog=begin;
	int pc=0;
	const char* datatype;
	int flush_needed=0;
	
	if(data_mask<=0xFF)
		datatype="char";
	else if(data_mask<=0xFFFF)
		datatype="short";
	else
		datatype="int";
	
	fprintf(out,
		"/* Created using bf2c from bftools-0.1\n** http://www.deepdarc.com/bf/\n*/\n" 
		"#include <stdio.h>\n\n"
		"int main(int argc, char* argv[])\n{\n"
		"\t%s data[65536]={0};\n"
		"\t%s* dp=data;\n"
		"\n",
		datatype,
		datatype
	);
	
	while(prog[pc].op)
	{
		switch(prog[pc].op)
		{
			case INST_SLEEP:
				fprintf(out,"\tusleep(%d*dp[0]);\n",(int)(prog[pc].count*SLEEP_MULTIPLIER+1));
				fprintf(out,"\tdp[%d]\t= 0;\n",prog[pc].arg2);
				break;

			case INST_SET_CONST:
				fprintf(out,"\tdp[%d]\t= %d;\n",prog[pc].arg2,prog[pc].count);
				break;

			case INST_SEEK_NZERO:
				fprintf(out,"\twhile(*dp) dp+=%d;\n",prog[pc].count);
				break;

			case INST_ADD_DATA:
				if(prog[pc].count==1)
					fprintf(out,"\tdp[%d]\t+= dp[0];\n",prog[pc].arg2);
				else
					fprintf(out,"\tdp[%d]\t+= dp[0] * %d;\n",prog[pc].arg2,prog[pc].count);
				break;

			case '+':
				if(prog[pc].count==1)
					fprintf(out,"\tdp[0]++;\n");
				else if(prog[pc].count==-1)
					fprintf(out,"\tdp[0]--;\n");
				else
					fprintf(out,"\tdp[0]\t+= %d;\n",prog[pc].count);
				break;
				
			case '>':
				if(prog[pc].count==1)
					fprintf(out,"\tdp++;\n");
				else if(prog[pc].count==-1)
					fprintf(out,"\tdp--;\n");
				else
					fprintf(out,"\tdp\t+= %d;\n",prog[pc].count);
				break;

			case ',':
				fprintf(out,"\tdp[0]\t= fgetc(stdin);\n");
				break;
				
			case '.':
				fprintf(out,"\tfputc(*dp,stdout);\n");
				flush_needed=1;
				break;
				
			case '[':
				if(flush_needed)
					fprintf(out,"\tfflush(stdout);\n");
				flush_needed=0;
					
				if(!pc || prog[pc-1].op!='[') 
					fprintf(out,"\tif(!*dp) goto pc%04d;\n",prog[pc].arg2);
				fprintf(out,"pc%04d:\n",pc);
				break;
				
			case ']':
				if(flush_needed)
					fprintf(out,"\tfflush(stdout);\n");
				flush_needed=0;

				if(!pc || prog[pc-1].op!=']') 
					fprintf(out,"\tif(*dp) goto pc%04d;\n",prog[pc].arg2);
				fprintf(out,"pc%04d:\n",pc);
				break;
		}
		pc++;
	}
	if(flush_needed)
		fprintf(out,"\tfflush(stdout);\n");
	fprintf(out,
		"\treturn *dp;\n"
		"}\n\n"
	);
}

void print_help()
{
	char usage[] = "%s [options] <BF-SOURCE> <INPUT-FILE> <OUTPUT-FILE>";
	struct {
		char* arg;
		char* desc;
	} args[] = {
		{ "--help", "Display this help" },
		{ "--7-bit", "Use 7-bit data" },
		{ "--8-bit", "Use 8-bit data" },
		{ "--16-bit", "Use 16-bit data" },
		{ "-8", "Use 8-bit data" },
		{ "-7", "Use 7-bit data" },
		{ "-c", "Convert BF program to C" },
		{ "-p", "Print out bfops at exit" },
		{ "-l", "If data pointer points to zero on exit, loop" },
		{ "-s", "Set sleep multiplier (Default=0.05)" },
		{ "-e", "Set EOF character value. Argument is an integer. (Default=no change)" },
		{ NULL }
	};
	int i;
	
	printf("USAGE:\n\t");
	printf(usage,"bf");
	printf("\n");
	for(i=0;args[i].arg!=NULL;i++)
	{
		printf(" %s %s%s\n",args[i].arg,"                "+strlen(args[i].arg),args[i].desc);
	}
}

int
main(int argc, char* argv[])
{
	FILE* progin=stdin;
	FILE* in=stdin;
	FILE* out=stdout;
	bfop prog[65535]={ {0} };
	unsigned int data[65535]={0};
	unsigned int stack[1024]={0};
	unsigned int depth=0;			// Depth tracker
	unsigned int pc=0;				// Program counter
	unsigned int di=0;				// data index
	
	unsigned long long tic=0;		// Total number of instructions executed
	int time_start=0;		// value of clock() at start of execution
	
	int bf2c_mode=0;
	int i;
	int file_count=0;
	int loop=0;
	
	/*
 --	** -- P R O C E S S   A R G U M E N T S -------------------------------------------------------
	*/
	
	// If we are evoked as "bf8", then go into 8-bit mode
	if(strcmp(argv[0],"bf8")==0)
	{
		data_mask=0x000000FF;
	}

	// If we are evoked as "bf2c", then go into bf2c mode
	if(strcmp(argv[0],"bf2c")==0)
	{
		bf2c_mode=1;
	}
	
	
	for(i=1;i<argc;i++)
	{
		if(argv[i][0]=='-' && argv[i][1]=='-')
		{
			if(strcmp(argv[i]+2,"help")==0)
			{
				print_help();
				return ERROR_HELP;
			}
			else
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
				print_bfops_at_exit=1;
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
					case 'p':
						print_bfops_at_exit=1;
						break;
					case '8':
						data_mask=0x000000FF;
						break;
					case '7':
						data_mask=0x0000007F;
						break;
					case 'c':
						bf2c_mode=1;
						break;
					case 'l':
						loop=1;
						break;
					case 'o':
						if(argv[i+1])
						{
							out=fopen(argv[i+1],"w");
							if(!out)
							{
								fprintf(stderr,"error: Unable to open \"%s\" for write access\n",argv[i+1]);
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
					case 'e':
						if(argv[i+1]) {
							i++;
							eof_character=strtol(argv[i],NULL,0);
						}
						else
						{
							fprintf(stderr,"error: Missing argument to '-%c'\n",argv[ii][j]);
							return ERROR_BAD_ARG;
						}
						break;
					case 's':
						if(argv[i+1])
						{
							sleep_multiplier=strtod(argv[i+1],NULL);
							if(sleep_multiplier < 0.0f)
								sleep_multiplier=0.0f;
							if(sleep_multiplier > 0.5f)
								sleep_multiplier=0.5f;
							fprintf(stderr,"info: sleep_multiplier=%f (should be '%s')\n",sleep_multiplier,argv[i+1]);
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
					fprintf(stderr,"error: Unable to open \"%s\" for read access\n",argv[1]);
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
		
	while( pc<MAX_PROG_SIZE-1 && (prog[pc].op=fgetc(progin)) != EOF)
	{
		prog[pc].count=0;
		prog[pc].arg2=0;
		switch(prog[pc].op)
		{
			case '-':
			case '<':
				prog[pc].op=prog[pc].op=='-'?'+':'>';
				if(pc && prog[pc].op=='-' && prog[pc-1].op==INST_SET_CONST)
				{
					prog[pc-1].count--;
				}
				else
				if(pc && prog[pc].op==prog[pc-1].op)
				{
					prog[pc-1].count--;
					if(prog[pc-1].count==0)
					{
						pc--;
					}
				}
				else
				{
					prog[pc].count=-1;
					prog[pc].arg2=0;
					pc++;
				}
				break;
				

			case '+':
			case '>':
				if(pc && prog[pc].op=='+' && prog[pc-1].op==INST_SET_CONST)
				{
					prog[pc-1].count++;
				}
				else
				if(pc && prog[pc].op==prog[pc-1].op)
				{
					prog[pc-1].count++;
					if(prog[pc-1].count==0)
					{
						pc--;
					}
				}
				else
				{
					prog[pc].count=1;
					prog[pc].arg2=0;
					pc++;
				}
				break;
				
			case '.':
			case ',':
				prog[pc].count=0;
				prog[pc].arg2=0;
				pc++;
				break;
			
			case '[':
				prog[pc].count=0;
				prog[pc].arg2=0;
				stack[depth++]=pc;
				pc++;
				break;
			
			case ']':
				depth--;
				prog[pc].arg2=stack[depth];
				prog[stack[depth]].arg2=pc;

#ifndef DISABLE_OPTIMIZATION
				{
					int opt_change=optimize(prog+stack[depth],prog+pc+1);
					if(opt_change)
					{
						pc-=opt_change;
					}
				}
#endif
				pc++;
				break;
				
			default:
				// Strip comments
				break;
		}
	}
	
	if(prog[pc].op!=EOF)
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
	
	prog[pc].op=0;
	pc=0;
	depth=0;
	
	/*
 --	** -- P R O G R A M   E X E C U T I O N -------------------------------------------------------
	*/
	
	if(bf2c_mode)
	{
		convert2c(prog,prog+pc,out);
		return 0;
	}
	
	{
		int ret=0;
		if(print_bfops_at_exit)
			do { ret=execute(prog,prog+pc,in,out); } while(loop && !ret);
		else
			do { ret=execute_fast(prog,prog+pc,in,out); } while(loop && !ret);
		return ret;
	}
}
