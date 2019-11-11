//Topological Sort (On DAGs) : O(V+E)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf ((int)(1e9))
#define N 1000

typedef struct graph_adj_list
{
	int node;
	struct graph_adj_list *next;
}node;

int V, E, pos;
int ver[N], vis[N] = {0};
node *adj[N] = {NULL};

void dfs(int x)
{
	node *temp = adj[x];

	if(vis[x])
		return;
	vis[x] = 1;

	while(temp != NULL)
	{
		dfs(temp->node);
		temp = temp->next;
	}

	ver[pos--] = x;
}

void topological_sort()
{
	int i;
	pos = V-1;
	for(i=0; i<V; i++)
		if(vis[i]==0)
			dfs(i);
}

int main()
{
	int i, x, y;
	node *temp;

	printf("\nEnter the number of vertices and edges : ");
	scanf("%d%d", &V, &E);

	printf("\nEnter the pair of edges(directed) (i, j) where 0<=i,j<n which form a DAG\n");
	for(i=0; i<E; i++)
	{
		scanf("%d%d", &x, &y);
		temp = (node*)malloc(sizeof(node));
		temp->next = adj[x];
		temp->node = y;
		adj[x] = temp;
	}

	topological_sort();

	printf("\nVertices in Topological Order\n");
	for(i=0; i<V; i++)
		printf("%d ", ver[i]);

	printf("\n\n");
}

/*

Test Case:
6 8
5 3
2 3
2 1
4 5
1 4
0 1
0 4
0 5

Possible Output:
2 0 1 4 5 3

*/