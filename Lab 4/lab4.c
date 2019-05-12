#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[10],ac[20],stk[15],act[10];
void check()
{
	strcpy(ac,"Reduce ");
	for(z=0;z<c;z++)
		if(stk[z]=='('&&stk[z+1]=='E'&&stk[z+2]==')')
		{
			stk[z]='F';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%sid",stk,a,ac);
			i=i-2;
		}
	for(z=0;z<c;z++)
		if(stk[z]=='i'&&stk[z+1]=='d')
		{
			stk[z]='F';
			stk[z+1]='\0';
			printf("\n$%s\t%s$\t%sid",stk,a,ac);
			j++;
		}
	for(z=0;z<c;z++)
	{
		if(stk[z]=='T'&&stk[z+1]=='*'&&stk[z+2]=='F')
		{
			stk[z]='T';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%sid",stk,a,ac);
			i=i-2;
		}
		else if(stk[z]=='F')
		{
			stk[z]='T';
			printf("\n$%s\t%s$\t%sid",stk,a,ac);
		}
	}
	for(z=0;z<c;z++)
	{
		if(stk[z]=='E'&&stk[z+1]=='+'&&stk[z+2]=='T'&&stk[z+3]=='*')
			break;
		if(stk[z]=='E'&&stk[z+1]=='+'&&stk[z+2]=='T'&&a[j+1]!='*')
		{
				stk[z]='E';
				stk[z+1]='\0';
				stk[z+2]='\0';
				printf("\n$%s\t%s$\t%sid",stk,a,ac);
				i=i-2;
		}
		else if(stk[z]=='T')
		{
			if(stk[z+1]=='*'||a[j+1]=='*')
				return;
			stk[z]='E';
			printf("\n$%s\t%s$\t%sid",stk,a,ac);
		}
	}
}
void main()
{
	printf("Grammar is\nE->E+T|T\nT->T*F|F\nF->(E)|id\n");
	printf("Enter the string\n");
	scanf("%s",a);
	c=strlen(a);
	strcpy(act,"Shift->");
	printf("Stack \t Input \t Action");
	for(i=0;j<c;i++,j++)
	{
		if(a[j]=='i'&&a[j+1]=='d')
		{
			stk[i]=a[j];
			stk[i+1]=a[j+1];
			stk[i+2]='\0';
			a[j]=' ';
			a[j+1]=' ';
			printf("\n$%s\t%s$\t%sid",stk,a,act);
		}
		else
		{
			stk[i]=a[j];
			stk[i+1]='\0';
			a[j]=' ';
			printf("\n$%s\t%s$\t%sid",stk,a,act);
		}
		check();
	}
	printf("\n");
}
