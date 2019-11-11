#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertionSort(int *a,int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(a[j] > key && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	return;	
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
	insertionSort(a,n);
	end = clock();
	printf("\n");
	printf("\n Sorted Order is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(a+i));
	}
	printf("\n Time taken is %f", (float)(end-start));
}	