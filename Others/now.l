%{
	int i=0;
%}

%%
([a-zA-Z0-9])* {i++;}
%%

int yywrap(void){}

main()
{
	yylex();
	printf("%d\n",i);
	i=0;
	return 0;
}
