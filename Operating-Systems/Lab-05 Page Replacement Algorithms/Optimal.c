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

int exists(int memoryTable[], int numberOfFrames, int page)
{
	for(int i=0; i<numberOfFrames; i++)
		if(page == memoryTable[i])
			return 1;
	return 0;
}

int getpos(int memoryTable[], int numberOfFrames, int pages[], int curr, int n)
{
	for(int i=0; i<numberOfFrames; i++)
		if(memoryTable[i] == -1)
			return i;

	int pos[N] = {0};
	for(int i=0; i<numberOfFrames; i++)
	{
		pos[i] = 1e9;
		for(int j=curr+1; j<n; j++)
			if(pages[j] == memoryTable[i])
			{
				pos[i] = j;
				break;
			}
	}

	int maxi = -1, retPos = -1;
	for(int i=0; i<numberOfFrames; i++)
		if(maxi < pos[i])
		{
			maxi = pos[i];
			retPos = i;
		}

	return retPos;
}

int main()
{
	system("clear");
	int n, pos = 0, numberOfFrames;
	int memoryTable[N], pages[N];

	for(int i=0; i<N; i++)
		memoryTable[i] = -1;

	printf("Enter number of frames : ");
	scanf("%d", &numberOfFrames);

	printf("Enter number of page requests: ");
	scanf("%d", &n);

	printf("Enter pages\n");
	for(int i=0; i<n; i++)
		scanf("%d", &pages[i]);

	int cnt = 0;
	printf("\nFrame table after each request\n");
	printf("---------------------------------\n");
	for(int i=0; i<n; i++)
	{	
		printf("Table after request %2d | ", pages[i]);
		if(!exists(memoryTable, numberOfFrames, pages[i]))
		{
			pos = getpos(memoryTable, numberOfFrames, pages, i, n);
			memoryTable[pos] = pages[i];

			printMemoryTable(memoryTable, numberOfFrames);
			printf("  Page Fault\n");
			cnt++;
			continue;
		}

		printMemoryTable(memoryTable, numberOfFrames);
		printf("\n");
	}

	printf("\nNumber of page faults : %d\n\n", cnt);
}
