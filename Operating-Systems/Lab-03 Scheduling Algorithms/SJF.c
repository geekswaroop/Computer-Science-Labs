#include<stdio.h>
int main()
{
    int n,at[10],bt[10],rt[10],wt[10],tat[10];
    printf("Enter no. of processes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter arrival time process %d:",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time process %d:",i+1);
        scanf("%d",&bt[i]);
        //rt[i]=bt[i];
    }
    bt[9]=9999;
    int time=0;
    int idt=0;
    int endtime=0;
    int remain=0;
    int finished[10]={0};
    while(remain!=n)
    {
        int smallest=9;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && bt[i]<bt[smallest] && finished[i]==0)
            {
                smallest=i;
            }
        }
        if(smallest==9)
        {
            idt++;
            time+=1;
        }
        else
        {
            printf("Process %d from %d to %d\n",smallest+1,time,time+bt[smallest]);
            remain++;
            finished[smallest]=1;
            endtime=time+bt[smallest];
            tat[smallest]=endtime-at[smallest];
            wt[smallest]=endtime-at[smallest]-bt[smallest];
            time+=bt[smallest];
        }

    }
    printf("\n\nProcess\tTurnaround Time\tWaiting Time\n\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",i+1,tat[i],wt[i]);
    }
    printf("CPU Idle Time is %d\n",idt);
    printf("Number of Context Swiches is %d\n",n-1);
}
