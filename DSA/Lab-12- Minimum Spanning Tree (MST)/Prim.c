//Implementation Prim's Algorithm : O((V+E)logV)
//Min-priority Queue implemented using min-heap.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf ((int)(1e9))
#define N 1000

typedef struct linked_list
{
	int node_des;
	int weight;
	struct linked_list *next;
}node;

node *adj[N] = {NULL};
int edges, nodes;
int min_heap[N][2], pos;
int visited[N];
//min_heap[x][0] - wight, min_heap[x][1] - destination node (to[x]).

void swap(int i, int j)
{
	int t1, t2;
	t1  = min_heap[i][0];
	t2 = min_heap[i][1];

	min_heap[i][0] = min_heap[j][0];
	min_heap[i][1] = min_heap[j][1];

	min_heap[j][0] = t1;
	min_heap[j][1] = t2;
}

void priority_enqueue(int w, int node)
{
	int temp;
	min_heap[++pos][0] = w;
	min_heap[pos][1] = node;
	temp =  pos;

	while(temp>1)
	{
		if(min_heap[temp][0] < min_heap[temp/2][0])
			swap(temp, temp/2);
		temp/=2;
	}
}

void min_heapify()
{
	int t1, t2;
	t1 = 1;
	while(t1<=pos)
	{
		if(min_heap[t1*2][0] < min_heap[t1*2 +1][0])
			t2 = t1*2;
		else
			t2 = t1*2 +1;

		if(min_heap[t1][0] > min_heap[t2][0])
		{
			swap(t1, t2);
			t1 = t2;
		}
		else
			break;
	}
}

int *priority_dequeue()
{
	min_heap[0][0] = min_heap[1][0];
	min_heap[0][1] = min_heap[1][1];

	min_heap[1][0] = min_heap[pos][0];
	min_heap[1][1] = min_heap[pos][1];

	min_heap[pos][0] = inf;
	min_heap[pos][1] = inf;

	pos--;
	min_heapify();

	return min_heap[0];
}

int isempty()
{
	if(pos == 0)
		return 1;
	return 0;
}

void clear()
{
	int i;
	for(i=0; i<N; i++)
	{
		min_heap[i][0] = inf;
		min_heap[i][1] = inf;
		visited[i] = 0;
	}
	pos = 0;
}

int prim()
{
	int total_min_weight = 0, i;
	int *ptr, x, w;
	node *temp;

	clear();
	priority_enqueue(0, 0); //Source vertex - 0, arbitraray weight -> 0 which doesn'temp affect total_min_weight

	while(!isempty())
	{
		ptr = priority_dequeue();
		x = ptr[1];
		w = ptr[0];

		if(visited[x]) //Check for cycle (ie. if x is already visited)
			continue;

		visited[x] = 1;
		total_min_weight += w;

		temp = adj[x];
		while(temp != NULL)
		{
			if(visited[temp->node_des] == 0)
				priority_enqueue(temp->weight ,temp->node_des);
			temp = temp->next;
		}
	}

	return total_min_weight;
}

int main()
{
	int i, min_cost, x, y, w;
	node *temp;

	printf("Enter number of nodes and edges : ");
	scanf("%d%d", &nodes, &edges);

	printf("\nEnter the pair of edges(undirected) with thier weights (i, j, w) where 0<=i,j<n\n");
	for(i=0; i<edges; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		temp = (node *)malloc(sizeof(node));
		temp->node_des = y;
		temp->weight = w;
		temp->next = adj[x];
		adj[x] = temp;

		temp = (node *)malloc(sizeof(node));
		temp->node_des = x;
		temp->weight = w;
		temp->next = adj[y];
		adj[y] = temp;
	}

	min_cost = prim();
	printf("\nTotal sum of edges in the MST is : %d\n\n", min_cost);
}

/*

Test Case : 
4 5
0 1 7
0 3 6
3 1 9
3 2 8
1 2 6

Output : 19

*/