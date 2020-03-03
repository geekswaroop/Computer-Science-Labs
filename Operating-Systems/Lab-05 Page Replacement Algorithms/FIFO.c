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

int exists(int memoryTable[], int numberOfFrames, int target)
{
	int i;
	for(i=0;i<numberOfFrames;i++)
	{
		if(memoryTable[i]==target)
			return 1;
	}
	return 0;
}

int main()
{
	int pages[N];
	int numberOfFrames, pos=0,n,pageFault=0,i,j,memoryTable[N];
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
	// for(i=0;i<n;i++)
	// {
	// 	if(!exists(pages, numberOfFrames, pages[i]))
	// 	{
	// 		memoryTable[pos] = pages[i];
	// 		pos = (pos+1)%numberOfFrames;
	// 		pageFault++;
	// 		printMemoryTable(memoryTable, numberOfFrames);
	// 	}
	// 	else
	// 	{
	// 		printMemoryTable(memoryTable, numberOfFrames);
	// 	}
	// 	printf("\n");
	// }
	for(int i=0; i<n; i++)
	{	
		printf("Table after request %2d | ", pages[i]);
		if(!exists(memoryTable, numberOfFrames, pages[i]))
		{
			memoryTable[pos] = pages[i];
			pos = (pos +1)%numberOfFrames;
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