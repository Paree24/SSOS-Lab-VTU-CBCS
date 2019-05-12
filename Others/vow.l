%{
	int vowels=0,cons=0;
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {cons++;}
%%

int yywrap(void){}

main()
{
	printf("Enter the string at the end press ctrl-d\n");
	yylex();
	printf("No of vowels %d\nNo of consonants %d\n",vowels,cons);
}
