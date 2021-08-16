#include<stdio.h>

int main(){

	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;

	printf("Enter number of processes:	");
	scanf("%d",&n);

	printf("Process name Arrival time Cpu time:\n\n");

	for(int i=0;i<n;i++)
	{

		printf("Arrival time of process[%d]	",i+1);
		scanf("%d",&at[i]);

		printf("Burst time of process[%d]	",i+1);
		scanf("%d",&bt[i]);

		printf("\n");
	}



	for(int j=0;j<n;j++)
	{

		sum+=bt[j];
		ct[j]+=sum;
	}



	for(int k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}


	for(int k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}

	printf("Solution Output: \n\n");

	for(int i=0;i<n;i++)
	{
		printf("\nProcess %d: Waiting Time:%d Turnaround Time:%d\n\n",i+1,wt[i],tat[i]);
	}
	printf("\n\nAverage Turnaround Time = %f\n\n",totalTAT/n);
	printf("Average Waiting Time = %f\n\n",totalWT/n);


}
