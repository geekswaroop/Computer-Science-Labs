#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 1000

void printMemoryTable(int memoryTable[], int numberOfFrames)
{
	for(int i=0; i<numberOfFrames; i++)
	{
		if(memoryTable[i] == -1)
			printf("-- ");
		else
			printf("%2d ", memoryTable[i]);
	}
	printf(" |");
}

int exists(int memoryTable[], int numberOfFrames, int target, int used[])
{
	int i;
	for(i=0;i<numberOfFrames;i++)
	{
		if(memoryTable[i]==target)
		{		
				used[i]++;
				return 1;
		}
	}
	return 0;
}
int getPos(int numberOfFrames, int used[])
{
	int i,minTime=10000000,pos=-1;
	for(i=0;i<numberOfFrames;i++)
	{
		if(used[i]<minTime)
		{
			minTime = used[i];
			pos = i;
		}
	}
	return pos;
}

int main()
{
	int pages[N];
	int numberOfFrames, pos=0,n,pageFault=0,i,j,memoryTable[N],used[N]={0};
	for(int i=0; i<N; i++)
		memoryTable[i] = -1;
	printf("Enter the numberOfFrames:\n");
	scanf("%d", &numberOfFrames);
	printf("Enter number of page requests:\n");
	scanf("%d", &n);
	printf("Enter the list of page requests:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &pages[i]);
	}

	for(int i=0; i<n; i++)
	{	
		printf("Table after request %2d | ", pages[i]);
		if(!exists(memoryTable, numberOfFrames, pages[i], used))
		{	
			int pos = getPos(numberOfFrames, used);
			memoryTable[pos] = pages[i];
			//pos = (pos +1)%numberOfFrames;
			used[pos]++;
			printMemoryTable(memoryTable, numberOfFrames);
			printf("  Page Fault\n");
			pageFault++;
			continue;
		}

		printMemoryTable(memoryTable, numberOfFrames);
		printf("\n");
	}
	printf("Number of Page Faults: %d\n", pageFault);

}