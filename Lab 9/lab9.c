#include<stdio.h>
#include<stdlib.h>
void FIFO(char s[],char F[],int l,int f)
{
		int i,j=0,k,flag=0; 
		printf("PAGE\tFRAMES\tFAULTS");
		for(i=0;i<l;i++)
		{
			for(k=0;k<f;k++)
				if(F[k]==s[i])
				    flag=1;
			printf("\n%c\t",s[i]);
			if(flag==0)
			{
				F[j++]=s[i];
		   		printf("%s",F);
				printf("\tFault");
			}
			else
			{
				flag=0;
		   		printf("%s",F);
				printf("\tHit");
			}
			if(j==f)
				j=0;
		}
}
void lru(char s[],char F[],int l,int f)
{
		int i,j=0,k,m,flag=0,top=0;
		printf("\nPAGE\t FRAMES\t FAULTS");
		for(i=0;i<l;i++)
		{
			for(k=0;k<f;k++)
				if(F[k]==s[i]) {
					flag=1;
					break;
				}
			printf("\n%c\t",s[i]);
			if(j!=f && flag!=1)
			{
				F[top]=s[i];
				if(++j!=f)
					top++;
			}
			else
			{
				if(flag!=1)
				{
					for(k=0;k<top;k++)
						F[k]=F[k+1];
					F[top]=s[i];
				}
				else
				{
					for(m=k;m<top;m++)
						F[m]=F[m+1];
					F[top]=s[i];
				}
			}
		printf("%s",F);
		if(flag==0)
			printf("\tFault");
		else
			printf("\tHit");
		flag=0;
		}
}
void main()
{
	int ch,i,l,f;
	char F[10],s[25];
	printf("Enter the no of empty frames: "); 
	scanf("%d",&f);
	F[f]='\0';
	printf("Enter the length of the string: ");
	scanf("%d",&l);
	printf("Enter the string: ");
	scanf("%s",s);
	while(1)
	{ 
		printf("\nEnter:\n1:FIFO\n2:LRU\n3:EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	for(i=0;i<f;i++)
					    F[i]=-1; 
				    FIFO(s,F,l,f);
				    break;
			case 2:	for(i=0;i<f;i++)
					    F[i]=-1;
				    lru(s,F,l,f);
				    break;
			case 3:	exit(0);
		}
	}
}
