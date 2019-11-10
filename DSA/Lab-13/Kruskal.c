//Implementation Kruskal's Algorithm : O(ElogV) (apart from sorting the edges)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

int edges, nodes;
int id[N], from[N], to[N], weight[N];

void initialize()
{
	int i;
	for(i=0; i<N; i++)
		id[i] = i;
}

int root(int x)
{
	//To identify which set the node belongs to ...
	while(id[x] != x)
	{
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void unionize(int x, int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

int kruskal()
{
	int total_min_weight = 0, i;

	for(i=0; i<edges; i++)
		if(root(from[i]) != root(to[i]))
		{
			total_min_weight += weight[i];
			unionize(from[i], to[i]);
		}

	return total_min_weight;
}

void swap(int i, int j)
{
	int t1, t2, t3;

	t1 = from[i];
	t2 = to[i];
	t3 = weight[i];

	from[i] = from[j];
	to[i] = to[j];
	weight[i] = weight[j];

	from[j] = t1;
	to[j] = t2;
	weight[j] = t3;
}

void sort()
{
	int i, j;
	//Selection sort (Easy to code)
	for(i=0; i<edges-1; i++)
		for(j=i+1; j<edges; j++)
			if(weight[i] > weight[j])
				swap(i, j);
}

int main()
{
	int i, min_cost;

	printf("Enter number of nodes and edges : ");
	scanf("%d%d", &nodes, &edges);

	printf("\nEnter the pair of edges(undirected) with thier weights (i, j, w) where 0<=i,j<n\n");
	for(i=0; i<edges; i++)
		scanf("%d%d%d", from+i, to+i, weight+i);

	initialize();
	sort();

	min_cost = kruskal();
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