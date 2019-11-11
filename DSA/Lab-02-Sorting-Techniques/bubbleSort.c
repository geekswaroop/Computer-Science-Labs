//Bubblesort using pointers
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void bubbleSort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(a+j) < *(a+i))
			{
				temp = *(a+j);
				*(a+j) = *(a+i);
				*(a+i) = temp;
			}

		}
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
	bubbleSort(a,n);
	end = clock();
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(a+i));
	}
	printf("\n Time taken is %f", (float)(end-start));
}