#include<stdio.h>

#define SYM_PI		(4)	// Inc Pointer	>
#define SYM_PD		(5)	// Dec Pointer 	<
#define SYM_DI		(6)	// Inc Data		+
#define SYM_DD		(7)	// Dec Data		-
#define SYM_OUT		(0)	// Char Out		
#define SYM_IN		(1)	// Char In
#define SYM_BB		(2)	// Block Begin	[
#define SYM_BE		(3)	// Block End	]

#define SYM_MASK	(7)	// Symbol Mask
#define SYM_COUNTABLE_MASK (1<<2)
#define MAX_COUNT	(30)

#define INST_ZERO		(-1)
#define INST_ADD		(-2)
#define INST_ADD_FWD	(-3)

#define INST_ONEBYTE 	(-50)
#define INST_QUITONEOF 	(-51)


#define encode_instruction(symbol, count) ((symbol&SYM_MASK)+(count<<3))
#define get_symbol(inst) (inst&SYM_MASK)
#define get_count(inst) (inst>>3)

#define TOTAL_PATTERNS	(sizeof(pattern_table)/sizeof(pattern_table[0]))
int pattern_table[][10] = {
	{ INST_ZERO, 3, SYM_BB, SYM_DD, SYM_BE },	// [-]
	{ INST_ZERO, 3, SYM_BB, SYM_DI, SYM_BE },	// [+]
	{ INST_ADD, 6, SYM_BB, SYM_PD, SYM_DI, SYM_PI, SYM_DD, SYM_BE },	// [<+>-]
	{ INST_ADD_FWD, 6, SYM_BB, SYM_PI, SYM_DI, SYM_PD, SYM_DD, SYM_BE },// [>+<-]
	{ INST_ADD, 6, SYM_BB,SYM_DD, SYM_PD, SYM_DI, SYM_PI, SYM_BE },	// [-<+>]
	{ INST_ADD_FWD, 6, SYM_BB,SYM_DD, SYM_PI, SYM_DI, SYM_PD, SYM_BE },// [->+<]
	{ INST_ONEBYTE, 4, SYM_DI, SYM_DI, SYM_DD, SYM_DD }, // ++--
	{ INST_QUITONEOF, 4, SYM_PI, SYM_PD, SYM_PI, SYM_PD }, // ><><
};

int
main(int argc, char **argv)
{
	int pc, args, xc=0, prog_len, l = 0;
	unsigned int x[32768*6];
	unsigned int p[32768*6];
    int tmp;
	int one_byte_fields=0;
	int auto_quit_on_eof=0;
	FILE *in_stream=stdin;
	FILE *prog_stream=stdin;
	FILE *out_stream=stdout;

	// If we were invoked as "bf8", then
	// we should be in 8 bit mode
	{
		int len=(strlen(argv[0]));
		if(len>=3 && strcmp(argv[0]+len-3,"bf8")==0)
			one_byte_fields=1;
	}

//  for (args = 1; args < argc; args++)
	if(argc>1)
	{
    	prog_stream = fopen(argv[1], "r");
		if(!prog_stream)
		{
			fprintf(stderr,"%s: Unable to open %s\n",argv[0],argv[1]);
			return 255;
		}
	}
	if(argc>2)
	{
    	in_stream = fopen(argv[2], "r");
		if(!in_stream)
		{
			fprintf(stderr,"%s: Unable to open %s\n",argv[0],argv[2]);
			return 255;
		}
	}
	if(argc>3)
	{
    	out_stream = fopen(argv[3], "w");
		if(!out_stream)
		{
			fprintf(stderr,"%s: Unable to open %s for output\n",argv[0],argv[3]);
			return 255;
		}
	}

	{

	
    prog_len = 0;
	
    for (pc = 0; pc < sizeof(p)/sizeof(p[0]) && (tmp = fgetc(prog_stream)) != EOF;)
    {
		switch(tmp)
		{
		case '>': p[pc++]=SYM_PI; prog_len++; break;
		case '<': p[pc++]=SYM_PD; prog_len++; break;
		case '+': p[pc++]=SYM_DI; prog_len++; break;
		case '-': p[pc++]=SYM_DD; prog_len++; break;
		case '.': p[pc++]=SYM_OUT; prog_len++; break;
		case ',': p[pc++]=SYM_IN; prog_len++; break;
		case '[': p[pc++]=SYM_BB; prog_len++; l++; break;
		case ']': p[pc++]=SYM_BE; prog_len++; l--; break;
		}
		if(l<0)
		{
			fprintf(stderr,"%s: Parse Error: Unmached ']'\n",argv[0]);
			return 254;
		}
	}
	if(l)
	{
		fprintf(stderr,"%s: Parse Error: Unmached '['\n",argv[0]);
		return 254;
	}

    pc = 0;

    if(prog_stream!=stdin)
		fclose(prog_stream);

	// postprocess
	for(pc=0,xc=0;pc<prog_len;)
	{
		int symbol=(p[pc]);
		int count=(0);
		int i;
		
		
		for(i=0;i<TOTAL_PATTERNS;i++)
		{
			int j;
			for(j=0;j<pattern_table[i][1];j++)
				if((pc+j)>=prog_len || p[pc+j]!=pattern_table[i][j+2])
					goto NO_PATTERN;
			p[xc++]=pattern_table[i][0];
			pc+=j;
			goto PATTERN_FOUND;
			NO_PATTERN:;
		}
		pc++;
//		if(symbol==SYM_BB && p[pc]==SYM_DD && p[pc+1]==SYM_BE)
//		{
//			p[xc++]=INST_ZERO;
//			pc+=2;
//			continue;
//		}
		if(symbol&SYM_COUNTABLE_MASK)
		{
			while(p[pc]==symbol && pc<prog_len && count<MAX_COUNT){count++; pc++; }
		}
		p[xc++]=encode_instruction(symbol,count);
		PATTERN_FOUND:
		while(0);
	}
	
	prog_len=xc;
	pc=0;

    for(xc = 0; xc < sizeof(x)/sizeof(x[0]); xc++)
      x[xc] = 0;

    xc = 0;

    for(pc = 0; pc < prog_len; pc++) {

		int symbol=(get_symbol(p[pc]));
		int count=(get_count(p[pc])+1);
		if(xc<0)
		{
			fprintf(stderr,"%s: Runtime Error: Pointer Underflow\n",argv[0]);
			return 254;
		}
		if(xc>=sizeof(x))
		{
			fprintf(stderr,"%s: Runtime Error: Pointer Overflow (Out of Memory)\n",argv[0]);
			return 254;
		}
		
		if(p[pc]==INST_ZERO) { x[xc]=0; continue; }
		if(p[pc]==INST_ADD) { x[xc-1]+=x[xc]; x[xc]=0; continue; }
		if(p[pc]==INST_ADD_FWD) { x[xc+1]+=x[xc]; x[xc]=0; continue; }
		if(p[pc]==INST_ONEBYTE && !one_byte_fields) { one_byte_fields=1; fprintf(stderr,"%s: using one-byte fields\n",argv[0]); continue; }
		if(p[pc]==INST_QUITONEOF) { auto_quit_on_eof=1; continue; }

      // '>'
      if (symbol == SYM_PI) xc+=count;

      // '<'
      else if (symbol == SYM_PD) xc-=count;

      // '+'
      else if      (symbol == SYM_DI) x[xc]+=count;

      // '-'
      else if (symbol == SYM_DD) x[xc]-=count;

      // '.'
      //else if (symbol == SYM_OUT) putchar(x[xc]);
      else if (symbol == SYM_OUT) fputc(x[xc],out_stream),fflush(out_stream);

      // ','
      else if (symbol == SYM_IN)
	  {
		int c=fgetc(in_stream);
		if(auto_quit_on_eof && c==EOF)
		   return 0;
		x[xc] = c;
	  }

      // '['
      else if (symbol == SYM_BB) {
        if (x[xc] == 0 || (one_byte_fields && (x[xc]&0xFF)==0)) {
          pc++;
          while (l > 0 || p[pc] != SYM_BE) {
            if (get_symbol(p[pc]) == SYM_BB) l++;
            else if (get_symbol(p[pc]) == SYM_BE) l--;
            pc++;
          }
        }
      }

      // ']'
      else if (symbol == SYM_BE) {
        pc--;
        while (l > 0 || p[pc] != SYM_BB) {
          if (get_symbol(p[pc]) == SYM_BE) l++;
          else if (get_symbol(p[pc]) == SYM_BB) l--;
          pc--;
        }
        pc--;
      }
    }  
  }
  return x[xc];
}
