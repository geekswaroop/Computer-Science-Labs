#include<stdio.h>
int main()
{
    int at[100],bt[100],rt[100],endTime,i,smallest,flag=0,idle_time=0,context_switches=0;
    int remain=0,n,time,sum_wait=0,sum_turnaround=0;
    printf("Enter no of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for Process P%d : ",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for Process P%d : ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
    rt[99]=10000;
    int prev_smallest = 10000;
    for(time=0;remain!=n;time++)
    {   prev_smallest=smallest;
        smallest=101;
        flag=0;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
            {   
                flag++;
                smallest=i;
            }
        }
        if(flag==0)
        {
            idle_time++;
        }
        if(prev_smallest!=smallest)
        {
            context_switches++;
        }
        rt[smallest]--;
        if(rt[smallest]==0)
        {
            remain++;
            endTime=time+1;
            printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-at[smallest],endTime-bt[smallest]-at[smallest]);
            // sum_wait+=endTime-bt[smallest]-at[smallest];
            // sum_turnaround+=endTime-at[smallest];
        }
    }
    // printf("\n\nAverage waiting time = %f\n",sum_wait*1.0/n);
    // printf("Average Turnaround time = %f",sum_turnaround*1.0/5);
    printf("Idle Time: %d\n", idle_time);
    return 0;
}
