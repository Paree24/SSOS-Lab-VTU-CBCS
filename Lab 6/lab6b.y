%{
	#include<stdio.h>
	#include<stdlib.h>
	int op=0,id=0,key=0,dig=0;
%}
%token DIGIT ID KEY OP
%%
input: 
DIGIT input {dig++;}
|ID input {id++;}
|KEY input {key++;}
|OP input {id++;}
|DIGIT {dig++;}
|ID {id++;}
|KEY {key++;}
|OP {id++;}
;
%%

extern int yylex();
extern int yyparse();
extern FILE *yyin;
main() {
	FILE *myfile=fopen("a.c","r");
	if(!myfile) {
		printf("Can't open a.c");
		return -1;
	}
	yyin=myfile;
	do{
		yyparse();
	  } while(!feof(yyin));
	printf("numbers=%d\n keywords=%d\n identifiers=%d\n operators=%d\n",dig,key,id,op);
	}
void yyerror() {
	printf("Parse error!");
	exit(-1);
	}
