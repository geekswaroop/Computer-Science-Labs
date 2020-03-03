// implementation of Worst - Fit algorithm -Fixed Size
#include<stdio.h> 

void worstFit(int blockSize[], int m, int processSize[], int n) 
{ 
	int allocation[n],i,j, done[m]; 

	for(i=0;i<n;i++)
	    allocation[i]=-1;
    for(i=0;i<m;i++)
	    done[i]=0;
    for (i=0; i<n; i++) 
    { 
        // Find the worst fit block for current process 
        int worstIdx = -1; 
        for (j=0; j<m; j++) 
        { 
            if (blockSize[j] >= processSize[i]  && done[j]==0) 
            { 
                if (worstIdx == -1) 
                    worstIdx = j; 
                else if (blockSize[worstIdx] < blockSize[j]) 
                    worstIdx = j; 
            } 
        } 
  
        // If we could find a block for current process 
        if (worstIdx != -1) 
        { 
            // allocate block j to p[i] process 
            allocation[i] = worstIdx; 
  
            // Reduce available memory in this block. 
            blockSize[worstIdx] -= processSize[i]; 
            done[worstIdx]=1;
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

	worstFit(blk, m, p, n); 

	return 0 ;
} 

/* testcase:
5 4
100 500 200 300 600
212 417 112 426
*/
