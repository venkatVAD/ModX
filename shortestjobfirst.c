#include<stdio.h>
#include<conio.h>
int main()
{
	int temp,total,i,j,n,time=0,avg_wt;
	float avg_tat;
	printf("\t\tEnter number of processes : ");
	scanf("%d",&n);
	int at[n],rt[n],P[n],bt[n],wt[n],tat[n],ct[n],Temp[n];
	float p[n];
	for(i=0;i<n;i++)
	{
		printf("\n\n\tEnter the details of P%d : ",i);
		scanf("%d %d",&at[i],&bt[i]);
		rt[i]=bt[i];
		P[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		if(at[i]==time)
		{
			time=bt[i];
			rt[i]=0;
			ct[i]=time;
		}
		else if(at[i]<time)
		{
			Temp[i]=time-at[i];
		}
	}
	for(i=0;i<n;i++)
	{
		if(rt[i]!=0)
		{
			p[i]=(1+(float)Temp[i]/(float)rt[i]);
		}
	}
	for(i=0;i<n;i++)
    {
        int pos=i;
        for(j=i+1;j<n;j++)
        {
            if(p[j]>p[pos])
                pos=j;
        }
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        temp=P[i];
        P[i]=P[pos];
        P[pos]=temp;
    }
	wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        wt[i]+=(ct[i-1]-at[i]);
        ct[i]=ct[i-1]+bt[i];
        total+=wt[i];
    }
    avg_wt=total/n;
    total=0;
    printf("\n\nProcess\t    Arrival Time    \tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("\nP[%d]\t\t  %d		%d\t\t%d\t\t\t%d",P[i],at[i],bt[i],wt[i],tat[i]);
	}
	avg_tat=(float)total/(float)n;
	printf("\n\nAverage Waiting Time=%d",avg_wt);
	printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
