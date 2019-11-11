#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < n-1; i++) 
    { 
       
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
    swap(&arr[min_idx], &arr[i]); 
    } 
} 
int main()
{
	int n,i;
	n=1000;
	srand(time(0));
	int p[n+5];
	int *a;
	a=p;
	for(i=0;i<n;i++)
	{
		*(a+i) = rand()%n;
		printf("%d ", *(a+i));
	}
	clock_t start,end;
	start= clock();
	selectionSort(a,n);
	end = clock();
	printf("\n");
	printf("\n Sorted Order is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(a+i));
	}
	printf("\n Time taken is %f", (float)(end-start));
} 