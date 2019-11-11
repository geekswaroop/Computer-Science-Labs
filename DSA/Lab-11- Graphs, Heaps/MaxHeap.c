//Heap sort - Max heap

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define inf ((int)(1e9))

int heap[500], pos = 0;

void swap(int i, int j)
{
	int t = heap[i];
	heap[i] = heap[j];
	heap[j] = t;
}

void insert(int num)
{
	int temp = pos+1;
	heap[++pos] = num;

	while(temp>1)
	{
		if(heap[temp] > heap[temp/2])
			swap(temp, temp/2);
		temp/=2;
	}
}

void max_heapify()
{
	int t1, t2;
	t1 = 1;
	while(t1<=pos)
	{
		if(heap[t1*2] > heap[t1*2 +1])
			t2 = t1*2;
		else
			t2 = t1*2 +1;

		if(heap[t1] < heap[t2])
		{
			swap(t1, t2);
			t1 = t2;
		}
		else
			break;
	}
}

void main()
{
	int n, a, i;

	printf("\nEnter the number of elements and the array : ");
	scanf("%d", &n);

	for(i=0 ; i<500; i++)
		heap[i] = -inf;

	for(i=0; i<n; i++)
	{
		scanf("%d", &a);
		insert(a);
	}

	printf("\nSorted array.\n");
	for(i=0; i<n; i++)
	{
		printf("%d ", heap[1]);
		heap[1] = heap[pos];
		heap[pos] = -inf;
		pos--;

		max_heapify();
	}
	printf("\n\n");
}