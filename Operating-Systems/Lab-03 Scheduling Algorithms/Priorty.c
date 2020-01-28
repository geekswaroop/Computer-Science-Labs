//Priorty - Non Premptive
#include <stdio.h>
#include <stdlib.h>

#define N 100
struct process{
	int waiting_time;
	int turn_around_time;
	int pid;
	int arrival_time;
	int burst_time;
    int priorty;
};

struct process p[N];
int n;
int cpu_idle;
void custom_sort()
{
	//Sort according to arrival time and then if same, pref given to priorty
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].arrival_time > p[j].arrival_time)
			{
				int temp_pid=p[i].pid;
				int temp_arrival_time=p[i].arrival_time;
				int temp_burst_time=p[i].burst_time;
				p[i].pid = p[j].pid;
				p[i].arrival_time = p[j].arrival_time;
				p[i].burst_time = p[j].burst_time;
				p[j].pid = temp_pid;
				p[j].arrival_time = temp_arrival_time;
				p[j].burst_time = temp_burst_time;
			}
            if(p[i].arrival_time == p[j].arrival_time)
            {
                if(p[i].priorty > p[j].priorty)
                {
                    int temp_pid=p[i].pid;
				    int temp_arrival_time=p[i].arrival_time;
				    int temp_burst_time=p[i].burst_time;
				    p[i].pid = p[j].pid;
				    p[i].arrival_time = p[j].arrival_time;
				    p[i].burst_time = p[j].burst_time;
				    p[j].pid = temp_pid;
				    p[j].arrival_time = temp_arrival_time;
				    p[j].burst_time = temp_burst_time;
                }
            }
		}
	}
}
void FCFS()
{	
	int i,j;
    int timer=0;
    timer+=p[0].burst_time+p[0].arrival_time;
    p[0].waiting_time = 0;
	cpu_idle = p[0].arrival_time;
    for(i=1;i<n;i++)
    {
        int t = p[i].arrival_time - timer;
        if(t>0)
        {
            cpu_idle+=t; 
            timer+=t;   
        }
        
        
        timer+=p[i].burst_time;
        //Waiting time calculation
        if(t<0)
            p[i].waiting_time = -t;
        
        else
        {
            p[i].waiting_time=0;
        }
        
    }
    //TAT Calculation = WT+BT
    for(i=0;i<n;i++)
    {
        p[i].turn_around_time = p[i].waiting_time+p[i].burst_time;
    }
}
int main()
{
	int i,j;
	printf("Enter the number of Processes\n");
	scanf("%d", &n);
	printf("Enter the arrival time of all the processes:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &p[i].arrival_time);
		p[i].pid = i+1;
	}
    printf("Enter the priorty of all the processes:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &p[i].priorty);
		p[i].pid = i+1;
	}
	printf("Enter the burst time of all the processes:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &p[i].burst_time);
		//p[i].pid = i+1;
	}
	custom_sort();
	FCFS();
	printf("\n");
	printf("\n Process \t Priorty \t Arrival Time \t Burst Time \t Waiting Time \t Turn Around Time\n");
	for(i=0;i<n;i++)
	{
		printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n", p[i].pid ,p[i].priorty ,p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turn_around_time);
	}
	printf("\nNumber of Context switches is %d\n", n-1);
	printf("Total CPU Idle Time is %d\n", cpu_idle);

}