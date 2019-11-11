 /*#include <stdio.h>
 #include <stdlib.h>
 #define SIZE 40

struct queue{
	int items[SIZE];
	int front;
	int rear;
};
//Queue functions
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node{
	int vertex;
	struct node* next;
};

struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};
//All graph functions
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void bfs(struct Graph* graph, int startVertex);

int main()
{	int i,temp,j,edge,var;
	printf("Enter the number of vertices in your graph:\n");
	scanf("%d", &temp);
	struct Graph* graph = createGraph(temp);
	printf("Enter the number of edges in your graph:\n");
	scanf("%d", &edge);
	printf("Enter the edges from source to destination:\n");
	for(var=0;var<edge;var++)
	{
		scanf("%d %d", &i,&j);
		//printf("%d %d", i,j);
		addEdge(graph, i, j);
	}
	printf("Enter the vertex from where you want to BFS:\n");
	scanf("%d", &temp);
	bfs(graph, temp);
	return 0;
}
void bfs(struct Graph* graph, int startVertex)
{
	struct queue* q = createQueue();
        
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
        
    while(!isEmpty(q)){
        //printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);
        
        struct node* temp = graph->adjLists[currentVertex];
        
        while(temp) {
            int adjVertex = temp->vertex;
            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
              temp = temp->next;
           }
        }
}
//Creating newNode for a linked list
struct node* createNode(int v)
{
	struct node* temp = (struct node*)(malloc(sizeof(struct node)));
	temp->vertex = v;
	temp->next = NULL;
	return temp;
}
//creating an empty graph Structure
struct Graph* createGraph(int vertices)
{
	struct Graph* g = (struct Graph*)(malloc(sizeof(struct Graph)));
	g->numVertices = vertices;
	//Allocate memory for each parts of Graph DS
	g->adjLists = (int*)(malloc((vertices*(sizeof(struct node*)))));
	g->visited = (int*)malloc(vertices*(sizeof(int*)));

	int i;
	for(i=0;i<vertices;i++)
	{
		g->adjLists[i] = NULL;
		g->visited[i]=0;
	}

	return g;
}

//Adding an edge to a graph
//We will be creating a node first. Push in the dest's data then it's next will be pointing to the adjList[src], same vice versa
void addEdge(struct Graph* graph, int src, int dest)
{	// Add edge from src to dest
        struct node* newNode = createNode(dest);
        newNode->next = graph->adjLists[src];
        graph->adjLists[src] = newNode;
     
        // Add edge from dest to src
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
}
    struct queue* createQueue() {
        struct queue* q = malloc(sizeof(struct queue));
        q->front = -1;
        q->rear = -1;
        return q;
    }
    int isEmpty(struct queue* q) {
        if(q->rear == -1) 
            return 1;
        else 
            return 0;
    }
    void enqueue(struct queue* q, int value){
        if(q->rear == SIZE-1)
            printf("\nQueue is Full!!");
        else {
            if(q->front == -1)
                q->front = 0;
            q->rear++;
            q->items[q->rear] = value;
        }
    }
    int dequeue(struct queue* q){
        int item;
        if(isEmpty(q)){
            printf("Queue is empty");
            item = -1;
        }
        else{
            item = q->items[q->front];
            q->front++;
            if(q->front > q->rear){
                //printf("Resetting queue");
                q->front = q->rear = -1;
            }
        }
        return item;
    }
    void printQueue(struct queue *q) {
        int i = q->front;
        if(isEmpty(q)) {
            printf("Queue is empty");
        } else {
            printf("\nQueue contains \n");
            for(i = q->front; i < q->rear + 1; i++) {
                    printf("%d ", q->items[i]);
            }
        }    
    }

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
}node;

int n, m;
int vis[500] = {0};
int q[500], f=1, r=0;
node *adj[500] = {NULL};

void enq(int n)
{
    q[++r] = n;
}

int deq()
{
    return q[f++];
}

int empty()
{
    return f>r;
}

void bfs(int x)
{
    node *t;
    int p;

    vis[x] = 1;
    enq(x);

    while(!empty())
    {
        p = deq();
        printf("%d ", p);
        t = adj[p];

        while(t != NULL)
        {
            if(vis[t->data] == 0)
            {
                vis[t->data] = 1;
                enq(t->data);
            }
            t = t->next;
        }
    }
}

void main()
{
    int i, a, b;
    node *t;

    printf("\nEnter number of nodes and edges : ");
    scanf("%d%d", &n, &m);

    printf("\nEnter the pair of edges(undirected) (i j) where 0<=i,j<n\n");
    for(i=0; i<m; i++)
    {
        scanf("%d%d", &a, &b);

        t = (node *)malloc(sizeof(node)); // Here, list node is pushed from the front
        t->data = b;
        t->next = adj[a];
        adj[a] = t; //a->b

        t = (node *)malloc(sizeof(node));
        t->data = a;
        t->next = adj[b];
        adj[b] = t; //b->a     
    }
    
    printf("\nOrder of traversal of nodes.\n");
    for(i=0; i<1; i++)
        if(vis[i] == 0)
            bfs(i);

    printf("\n\n");
}

/*
Graph Input :
7 8
3 4
3 0
4 2
0 2
2 6
2 1
1 5
0 1
*/