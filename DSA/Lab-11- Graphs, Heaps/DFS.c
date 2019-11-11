#include<stdio.h>

int adj[100][100];
int visited[100]={0};
int v;
void dfs(int i)
{
	int j;
	printf("%d \n", i);
	visited[i]=1;
	for(j=1;j<=v;j++)
	{
		if(!visited[j] && adj[i][j]==1)
		{
			dfs(j);
		}
	}
}
int main()
{
	printf("Please enter the number of vertices in the graph:\n");
	int i,j,src,dest,e;
	scanf("%d", &v);
	printf("Enter the number of edges in the graph:\n");
	scanf("%d", &e);
	printf("Enter the edges of the graph:\n");
	for(i=0;i<e;i++)
	{
		scanf("%d %d", &src, &dest);
		adj[src][dest]=1;
		adj[dest][src]=1;
	}
	//Initialising visited to zero
	for(i=1;i<=v;i++)
	{
		visited[i]=0;
	}
	dfs(1);
}

/*#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]
 
void main()
{
    int i,j;
    printf("Enter number of vertices:");
   
	scanf("%d",&n);
 
    //read the adjecency matrix
	printf("\nEnter adjecency matrix of the graph:");
   
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
 
    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(0);
}
 
void DFS(int i)
{
    int j;
	printf("\n%d",i);
    visited[i]=1;
	
	for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}*/