%{
	int id=0,d=0,op=0,plus=0,mins=0,mul=0,divs=0,top=-1,valid=1;
	char stack[50];
%}

%%
[0-9]+ {d++;}
[a-zA-Z]+ {id++;}
[+] {op++;plus++;}
[-] {op++;mins++;}
[*] {op++;mul++;}
[/] {op++;divs++;}
\{ {stack[++top]='{';}
\} {if(stack[top--]!='{') valid=0;}
\[ {stack[++top]='[';}
\] {if(stack[top--]!='[') valid=0;}
\( {stack[++top]='(';}
\) {if(stack[top--]!='(') valid=0;}
%%

int yywrap(void){}

main()
{
	printf("Enter the expression:\n");
	yylex();
	if(valid==1&&top-1&&((d+id)==op+1||op==1))
	{
		  printf("Valid input\n");
		  printf("No of identifiers %d\ndigits %d\noperators %d\nplus%d\nminus%d\nmul%d\ndiv%d\n",id,d,op,plus,mins,mul,divs);  
	}
}
