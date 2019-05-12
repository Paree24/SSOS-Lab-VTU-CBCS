%{
	int words=0,letters=0,digits=0,line=0;
%}

%%
[0-9] {digits++;}
[a-zA-Z] {letters++;}
[\t ' '] {words++;}
"\n" {words++;line++;}
%%

int yywrap(void){}

main()
{
	printf("Enter the string at the end press ctrl-d\n");
	yylex();
	printf("No of words %d\ndigits %d\nletters %d\n lines %d\n",words,digits,letters,line);
}
