// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
// 	int n,m,i,j,k,p,q,r;
// 	printf("Enter the number of processes:\n");
// 	scanf("%d", &n);
// 	printf("Enter the total number of resource types:\n");
// 	scanf("%d", &m);
// 	int max[n][m];
// 	int allocation[n][m];
// 	int need[m][n];
// 	int available[m];
// 	//Taking in max need
// 	printf("Enter the max need of each process:\n");
// 	for(i=0;i<n;i++)
// 	{
// 		for(j=0;j<m;j++)
// 		{
// 			scanf("%d", &max[i][j]);
// 		}
// 	}
// 	//Taking in allocation
// 	printf("Enter the current allocation of each process:\n");
// 	for(i=0;i<n;i++)
// 	{
// 		for(j=0;j<m;j++)
// 		{
// 			scanf("%d", &allocation[i][j]);
// 		}
// 	}
// 	//Taking in availability
// 	int work[m]; 
// 	printf("Enter the current availability of each resource:\n");
// 	for(i=0;i<m;i++)
// 	{
// 		scanf("%d", &available[i]);
// 		work[i]=available[i];
// 	}
// 	//Populating need matrix
// 	for(i=0;i<n;i++)
// 	{
// 		for(j=0;j<m;j++)
// 		{
// 			need[i][j] = max[i][j]-allocation[i][j];
// 		}
// 	}
// 	//Initialising finish[n]
// 	int finish[n];
// 	for(i=0;i<n;i++)
// 	{
// 		finish[i]=0;
// 	}

// 	//Main Algorithm starts here
// 	int flag,incr=0;
// 	int ans[n];
// 	for(p=0;p<5;p++)
// 	{
// 		for(i=0;i<n;i++) //Run loop for each process
// 		{	
// 			if(finish[i]==0) //Check if it's not finished
// 			{	flag=1;
// 				for(j=0;j<m;j++)
// 				{
// 					if(need[i][j]>available[j]);
// 					{
// 						flag=0;
// 						break;
// 					}
// 				}
// 				if(flag!=0)
// 				{
// 					ans[incr++]=i;
// 				// work[i] = work[i]+availability[i];
// 					for(k=0;k<m;k++)
// 					{
// 						available[k] = available[k]+allocation[i][k];
// 					}
// 					finish[i]=1;
// 				}
// 			}
// 		}
// 	}
// 	printf("Safe Sequence is as follows:\n");
// 	for(i=0;i<n;i++)
// 	{
// 		printf("%d ", ans[i]);
// 	}

// }

#include <stdio.h> 
int main() 
{ 
	int n, m, i, j, k,p; 

	printf("Enter the number of processes:\n");
	scanf("%d", &n);
	printf("Enter the total number of resource types:\n");
	scanf("%d", &m);
	int max[n][m];
	int alloc[n][m];
	int need[m][n];
	int avail[m];
	//Taking in max need
	printf("Enter the max need of each process:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d", &max[i][j]);
		}
	}
	//Taking in allocation
	printf("Enter the current allocation of each process:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d", &alloc[i][j]);
		}
	}
	//Taking in availability
	int work[m]; 
	printf("Enter the current availability of each resource:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d", &avail[i]);
		work[i]=avail[i];
	}

	int f[n], ans[n], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	//int need[n][m]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < m; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < m; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	printf("Following is the SAFE Sequence\n"); 
	for (i = 0; i < n - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[n - 1]); 

	return (0); 

	
} 
