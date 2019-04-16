#include<conio.h>
#include<stdio.h>
int main()
{
	int available[10],p[10],i,j,k,count,count1,nor,nop;
	int need[10][10],allocated[10][10],maximum[10][10];
	
	r:;
	printf("\nEnter number of process :");
	scanf("%d",&nop);
	printf("\nEnter  resources available : ");
	scanf("%d",&nor);
	printf("\nEnter insatnces for resources :\n");
	int a=65;
	for(i=0;i<nor;i++)
	{  
		printf("%c",a+i);
		scanf("%d",&available[i]);
	}
	printf("\nEnter allocation matrix  \n");
	for(i=0;i<nop;i++)
	{
		printf("P%d\n",i+1);          
		p[i]=0;
		for(j=0;j<nor;j++)
		{
			scanf("%d",&allocated[i][j]);
		}
	}
  	printf("\nEnter maximum matrix  \n");

 	for(i=0;i<nop;i++)
	{
		printf("P%d\n",i+1);
		for(j=0;j<nor;j++)
		{
			scanf("%d",&maximum[i][j]);
		}
	}
	for(i=0;i<nop;i++)
	{
 		printf("\nP%d\t",i+1) ;
 		for(j=0;j<nor;j++)
 		{
			need[i][j]=maximum[i][j]-allocated[i][j];
			printf("\t%d",need[i][j]);
		}
	}
	k=0;     
	count=0;
	printf("\n\n");
	while(k<15)
	{
		for(i=0;i<nop;i++)
		{  
			count1=0;
			for(j=0;j<nor;j++)
			{
				if(p[i]==1) 
					break;
				if(need[i][j]<=available[j])
				{
					count1++;
				}
				if(count1==nor)
				{
					for(j=0;j<nor;j++)
					{
						available[j]+= allocated[i][j];
					}
					printf("P%d\t",i+1);  
					p[i]=1;     
					count++;
				}
			}
		} 
		k++;
	}
	if(count<nop-1)
	{
		printf("\nDeadlock, not in safe state ");
	}
	
	char h;
	printf("\nPress 'h' if you want to check another set of processes:");
	scanf("%s",&h);
	if(h=='h')
		goto r;
	
	getch();
}
