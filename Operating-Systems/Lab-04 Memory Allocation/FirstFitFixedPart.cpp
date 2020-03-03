// implementation of First - Fit algorithm -Fixed Size
#include<stdio.h> 

void firstFit(int blockSize[], int m, 
			int processSize[], int n) 
{ 
	int allocation[n], i, j, done[m]; 

	for(i=0;i<n;i++)
	    allocation[i]=-1;
    for(i=0;i<m;i++)
	    done[i]=0;
	for (i = 0; i < n; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
			if (blockSize[j] >= processSize[i] && done[j]==0) 
			{ 
				allocation[i] = j; 
				done[i]=1;
				// Reduce available memory in this block. 
				blockSize[j] -= processSize[i]; 

				break; 
			} 
		} 
	} 

	printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
	for (i = 0; i < n; i++) 
	{ 
		printf(" %d\t\t%d\t\t", i+1 ,processSize[i]); 
		if (allocation[i] != -1) 
			printf("%d\n",allocation[i] + 1); 
		else
			printf("Not Allocated\n");
	} 
} 

int main() 
{ 
	/* int blockSize[] = {100, 500, 200, 300, 600}; 
	int processSize[] = {212, 417, 112, 426}; 
	int m = sizeof(blockSize) / sizeof(blockSize[0]); 
	int n = sizeof(processSize) / sizeof(processSize[0]); */
	
	int m,n,i,j=0; //number of blocks,processes
	scanf("%d %d",&m,&n);
	int blk[m],p[n];
	for(i=0;i<m;i++)
	scanf("%d",&blk[i]);
	for(i=0;i<n;i++)
	   scanf("%d",&p[i]);

	firstFit(blk, m, p, n); 

	return 0 ; 
} 

/* testcase:
5 4
100 500 200 300 600
212 417 112 426
*/

