#include <stdio.h>


int main()
{
 char buffer[65356*100]={0};
 char *cur ;
 int buf_end = 0 ;
 char ch = (char)fgetc( stdin ) ;
 int move[500]={0} ;
 int mdepth = 0 ;
 int depth = 1 ;
  

 printf( "#include <stdio.h>\n"
	 "\n"
	 "int main(int argc, char* argv[])\n"
	 "{\n"
	 " int a[65355+100]={0} , *p;\n"
	 "unsigned short i;\n"
	 "FILE* in=stdin;\n"
	 "FILE* out=stdout;\n"	 
	 "\n"
	 " p = a ;\n"
	 "if(argc>1){in=fopen(argv[1],\"r\");\n"
	 "if(!in) { fprintf(stderr,\"error: Unable to open \\\"%%s\\\" for read access\\n\",argv[1]); return -1; }}\n"
	 "if(argc>2){out=fopen(argv[2],\"w\");\n"
	 "if(!out) { fprintf(stderr,\"error: Unable to open \\\"%%s\\\" for write access\\n\",argv[2]); return -1; }\n"
	 "}\n"
	);

 
 move[ mdepth ] = 0 ;
 while ( !feof( stdin ) )
 {
    if ( ch == '+' || ch == '-' ||
	 ch == '<' || ch == '>' ||
	 ch == '.' || ch == ',' ||
	 ch == '[' || ch == ']' )
       buffer[ buf_end++ ] = ch ;
    ch = (char)fgetc( stdin ) ;
 }
 buffer[ buf_end ] = '\0' ;

 cur = buffer ;
     
 
 while ( *cur )
 {
    switch( *cur )
    {
       case '+':
       case '-':
       {
	  int val = 0 ;
	  for( ; *cur == '+' || *cur == '-'; cur++ )
	     val += *cur == '+' ? 1 : -1 ;
	  if ( val == 1 )
	     printf("p[%d]++;\n",  move[mdepth] ) ; 
	  else if ( val == -1 )
	     printf("p[%d]--;\n",  move[mdepth] ) ; 
	  else if ( val > 0 )
	     printf("p[%d] += %d;\n", 
		    move[mdepth], val) ; 
	  else if ( val < 0 )
	     printf("p[%d] -= %d;\n", 
		    move[mdepth], -val) ; 
       }
       break ;
       case '<':
       case '>':
       {
	  int val = 0 ;
	  for( ; *cur == '<' || *cur == '>'; cur++ )
	     val += *cur == '>' ? 1 : -1 ;
	  move[mdepth] += val ;
       }
       break ;
       case '.':  
          printf("fputc( p[%d], out ) ; fflush( out ) ;\n",
		  move[mdepth] ) ; 
          cur++;
          break ;
       case ',':  
          printf("p[%d] = fgetc( in ) ;\n",
		  move[mdepth]) ; 
          cur++;
          break ;
       case '[':
       {
	  int s = 1;
	  int m = 0;
	  int mval = 0;
	  int vars[30];
	  int added[30];
	  int nr_vars = 0;
	  int succ = 1;
             
	  for ( s = 1; cur[s] == '+' || cur[s] == '-' ||
		   cur[s] == '<' || cur[s] == '>' ; s++ )
	  {
	     if ( cur[s] == '<' )
		m-- ;
	     else if ( cur[s] == '>' )
		m++ ;
	     else if ( m == 0 )
		mval += cur[s] == '+' ? 1 : -1 ;
	     else
	     {
		int i ;
		for ( i = 0; i < nr_vars && m != vars[ i ]; i++ ) ;
		if ( i == nr_vars )
		{
		   vars[i] = m ;
		   added[i] = 0 ;
		   nr_vars++ ;
		}
		added[i] += cur[s] == '+' ? 1 : -1 ;
	     }
	  }
	  if ( cur[s] == ']' && m == 0 && mval == -1 )
	  {
	     int i ;
	     printf("", depth, depth, "" ) ;
	     for ( i = 0; i < nr_vars; i++ )
		if ( added[i] == 1 )
		   printf("p[%d] += p[%d] ; ", 
			  move[mdepth] + vars[i], move[mdepth] );
		else if ( added[i] == -1 )
		   printf("p[%d] -= p[%d] ; ", 
			  move[mdepth] + vars[i], move[mdepth] );
		else if ( added[i] > 0 )
		   printf("p[%d] += %d * p[%d] ; ", 
			  move[mdepth] + vars[i], added[i], move[mdepth] );
		else if ( added[i] < 0 )
		   printf("p[%d] -= %d * p[%d] ; ",
			  move[mdepth] + vars[i], -added[i], move[mdepth] );
	     printf("p[%d] = 0 ;\n",  move[mdepth] );
	  cur += s + 1;
	  }
	  else
	  {
	     printf("while( p[%d] ) {\n",  move[mdepth] ) ;
	     //depth += 2;
	     move[mdepth+1] = move[mdepth] ;
	     mdepth++;
	     cur++;
	  }
       }
       break ;
       case ']':
       {
	  int val = move[mdepth] - move[mdepth-1] ;
	  if ( val == 1 )
	     printf("p++;\n", depth, depth, "") ; 
	  else if ( val == -1 )
	     printf("p--;\n", depth, depth, "") ; 
	  else if ( val > 0 )
	     printf("p += %d;\n",  val) ; 
	  else if ( val < 0 )
	     printf("p -= %d;\n",  -val) ; 
	  //depth -= 2;
	  mdepth-- ;
	  printf("}\n", depth, depth, "") ;
	  cur++;
	  break ;
       }
    }
 }
 printf( "}\n" ) ;
 return 0;
}
