%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
start:exp {printf("%d\n",$$);}
exp:exp'+'exp {$$=$1+$3;}
	|exp'-'exp {$$=$1-$3;}
	|exp'*'exp {$$=$1*$3;}
	|exp'/'exp {
	if($3==0)
	{
		yyerror();
		exit(0);
	}
	else
		{
		$$=$1/$3;
		}
	}
	|'('exp')' {$$=$2;}
	|NUM {$$=$1;}
%%
main()
{
	printf("Enter the expression\n");
	yyparse();
}
yywrap() {}
yyerror()
{
	printf("Error\n");
}
