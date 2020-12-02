#include <stdio.h>
#include <stdlib.h>

#define N 100
struct process{
	int waiting_time;
	int turn_around_time;
	int pid;
	int arrival_time;
	int burst_time;
};

struct process p[N];
int n;
void sort()
{
	//Sort according to arrival time
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
		}
	}
}
void FCFS()
{	
	int i,j;
	//First assign waiting_time[p0] = 0
	p[0].waiting_time = 0;
	//Next, lets calculate wt[i] = summation of bt[0...i-1] - at[i]
	for(i=1;i<n;i++)
	{	int temp_summation=0;
		for(j=0;j<i;j++)
		{
			temp_summation+=p[j].burst_time;
		}
		p[i].waiting_time = temp_summation - p[i].arrival_time;
	}
	//Next, TAT = WT + BT for each process
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
	printf("Enter the burst time of all the processes:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &p[i].burst_time);
		//p[i].pid = i+1;
	}
	sort();
	FCFS();
	printf("\n");
	printf("\n Process \t Arrival Time \t Burst Time \t Waiting Time \t Turn Around Time\n");
	for(i=0;i<n;i++)
	{
		printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d\n", p[i].pid ,p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turn_around_time);
	}
	printf("\nNumber of Context switches is %d\n", n-1);
	int total_end_time = p[n-1].waiting_time + p[n-1].burst_time+p[n-1].arrival_time;
	int total_burst_time=0;
	for(i=0;i<n;i++)
	{
		total_burst_time+=p[i].burst_time;
	}
	int cpu_idle_time = total_end_time-total_burst_time;
	printf("Total CPU Idle Time is %d\n", cpu_idle_time);

}