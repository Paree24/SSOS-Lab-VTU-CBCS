%{
	#include<stdio.h>
	int ml=0,sl=0;
%}
%%
"//"(.*) {sl++;}
"/*"[a-zA-z0-9' '\n \t]+"*/" {ml++;}
%%
main()
{
	yyin=fopen("input.c","r");
	yyout=fopen("out.c","w");
	yylex();
	printf("Single Line = %d \nMulti Line=%d \n",sl,ml); 
	return 0;
}
int yywrap(void) {}
