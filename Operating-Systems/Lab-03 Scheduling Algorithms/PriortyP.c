#include<stdio.h>
int main()
{
    int n,at[10],bt[10],rt[10],wt[10],tat[10],prio[10];
    printf("Enter no. of processes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter arrival time process %d:",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time process %d:",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
        printf("Enter priority of process %d:",i+1);
        scanf("%d",&prio[i]);
    }
    prio[9]=9999;
    int time=0;
    int idt=0;
    int endtime=0;
    int remain=0;
    int cntx=0;
    int prev;
    while(remain!=n)
    {
        int smallest=9;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && prio[i]<prio[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }
        if(time>=1 && smallest!=prev)
            cntx++;
        prev=smallest;
        if(smallest==9)
            idt++;
        else
        {
            rt[smallest]--;
            printf("Process %d from %d to %d\n",smallest+1,time,time+1);
            if(rt[smallest]==0)
            {
                remain++;
                endtime=time+1;
                tat[smallest]=endtime-at[smallest];
                wt[smallest]=endtime-at[smallest]-bt[smallest];
            }
        }
        time+=1;
    }
    printf("\n\nProcess\tTurnaround Time\tWaiting Time\n\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",i+1,tat[i],wt[i]);
    }
    printf("CPU Idle Time is %d\n",idt);
    printf("Number of Context Swiches is %d\n",cntx);
}
