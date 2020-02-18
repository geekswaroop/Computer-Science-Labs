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
        rt[i]=bt[i];
    }
    rt[9]=-1;
    int time=0;
    int idt=0;
    int endtime=0;
    int remain=0;
    int cntx=0;
    int prev;
    while(remain!=n)
    {
        int largest=9;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>rt[largest] && rt[i]>0)
            {
                largest=i;
            }
        }
        if(time>=1 && rt[largest]==rt[prev])
            largest=prev;
        if(time>=1 && largest!=prev)
            cntx++;
        prev=largest;
        if(largest==9)
            idt++;
        else
        {
            rt[largest]--;
            printf("Process %d from %d to %d\n",largest+1,time,time+1);
            if(rt[largest]==0)
            {
                remain++;
                endtime=time+1;
                tat[largest]=endtime-at[largest];
                wt[largest]=endtime-at[largest]-bt[largest];
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
