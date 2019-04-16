#include<stdio.h>
#include<string.h>

void main()
{
	int i,j,bt[10],p[10],weightTime[10],tWeight=0,pt[10],temp,temp1,nop;
	float avgWeight;
 
	printf("Enter number of processes:"); 
	scanf("%d",&nop);
	for(i=0;i<nop;i++)
	{
		printf("Enter Burst time for process P%d:",i+1);
		p[i] = i+1;
		scanf("%d",&bt[i]);
		printf("Eter Priority for process P%d:",i+1);
		scanf("%d",&pt[i]);
	}
  
	for(i=0;i<nop-1;i++)
	{
		for(j=i+1;j<nop;j++)
		{
			if(pt[i]>pt[j])
			{
				temp1=pt[i];
				pt[i]=pt[j];
				pt[j]=temp1;
				temp1=bt[i];
				bt[i]=bt[j];
				bt[j]=temp1;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
  
	weightTime[0]=0;
	for(i=1;i<nop;i++)
	{
		weightTime[i]=weightTime[i-1]+bt[i-1];
		tWeight=tWeight+weightTime[i];
	}
   
	avgWeight=(float)tWeight/nop;
   
	printf("Process Name\t | Burst Time\t | Priority\t | Weight Time\n");
    
	for(i=0;i<nop;i++)
    {
		printf(" %d\t\t | %d\t\t | %d\t\t | %d\n" ,p[i],bt[i],pt[i],weightTime[i]);
	}
  
	printf("Total Waiting Time=%d\nAveage Waiting Time=%f",tWeight,avgWeight);
}
