//Bellman-Ford's Algorithm : O(VE)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf ((int)(1e9))
#define N 1000

typedef struct tuple
{
	int node1;
	int node2;
	int weight;
}tuple;

int E, V;
int dis[N];
tuple edges[N];

int bellman_ford()
{
	int i, j;

	for(i=1; i<V; i++)
		dis[i] = inf;
	dis[0] = 0;

	for(i=0; i<V-1; i++)
		for(j=0; j<E; j++)
		{
			if(dis[edges[j].node1] > dis[edges[j].node2] + edges[j].weight)
				dis[edges[j].node1] = dis[edges[j].node2] + edges[j].weight;

			if(dis[edges[j].node2] > dis[edges[j].node1] + edges[j].weight)
				dis[edges[j].node2] = dis[edges[j].node1] + edges[j].weight;
		}

	for(i=0; i<E; i++)
	{
		if(dis[edges[i].node1] > dis[edges[i].node2] + edges[i].weight)
			return 0;

		if(dis[edges[i].node2] > dis[edges[i].node1] + edges[i].weight)
			return 0;
	}

	return 1;
}

int main()
{
	int i, min_cost;

	printf("Enter number of nodes and edges : ");
	scanf("%d%d", &V, &E);

	printf("\nEnter the pair of edges(undirected) with thier weights (i, j, w) where 0<=i,j<n\n");
	for(i=0; i<E; i++)
		scanf("%d%d%d", &edges[i].node1, &edges[i].node2, &edges[i].weight);


	if(bellman_ford())
	{
		printf("\nMinimum distance from sorce vertex(0) for node 0 to %d are\n", V-1);
		for(i=0; i<V; i++)
			printf("%d ", dis[i]);
	}
	else
		printf("Negative Cycle Present.");

	printf("\n\n");
}

/*

Test Case 1:
5 5
0 1 5
0 2 2
2 3 1
0 3 6
2 4 5

Output:
0 5 2 3 7

x------------x

Test Case 2:
5 5
0 1 5
0 2 2
2 3 1
0 3 -6
2 4 5

Output:
Negative Cycle Present.

*/