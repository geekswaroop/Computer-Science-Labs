/*#include <stdio.h>
#include <stdlib.h>

struct QNode{
	int key;
	struct QNode* next;
};
struct Queue{
	struct QNode *rear, *front;
};

struct QNode* newNode(int k)
{
	struct QNode* temp = (struct QNode*)(malloc(sizeof(struct QNode)));
	temp->key = k;
	temp->next = NULL;
	return temp;
}
//Creating Empty queue
struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)(malloc(sizeof(struct Queue)));
	q->rear = q->front = NULL;
	return q;
}
void enQueue(struct Queue* q, int key)
{
	struct QNode* temp = newNode(key);
	//temp->next = NULL;
	if(q->rear == NULL) //Checks if the queue is null
	{
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}
struct QNode* deQueue(struct Queue* q)
{
	struct QNode* temp = q->front;
	if(temp == NULL)
	{
		return NULL;
	}
	free(temp);
	q->front = q->front->next;
	if(q->front == NULL)
	{
		q->rear = NULL;
	}
	return temp;
}
int main()
{
	struct Queue* q = createQueue(); 
    enQueue(q, 10); 
    enQueue(q, 20); 
    deQueue(q); 
    deQueue(q); 
    enQueue(q, 30); 
    enQueue(q, 40); 
    enQueue(q, 50); 
    struct QNode* n = deQueue(q); 
    if (n != NULL) 
        printf("Dequeued item is %d", n->key); 
    return 0; 
}*/

/*#include <stdio.h> 
#include <stdlib.h> 

//LL
struct QNode { 
	int key; 
	struct QNode* next; 
}; 

//Queue stores front and rear of LL
struct Queue { 
	struct QNode *front, *rear; 
}; 

// create a new linked list node. 
struct QNode* newNode(int k) 
{ 
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
	temp->key = k; 
	temp->next = NULL; 
	return temp; 
} 

//create an empty queue 
struct Queue* createQueue() 
{ 
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL; 
	return q; 
} 


void enQueue(struct Queue* q, int k) 
{ 
	// Create a new LL node 
	struct QNode* temp = newNode(k); 

	//q is empty
	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 

	
	q->rear->next = temp; 
	q->rear = temp; 
} 

// Function to remove a key from given queue q 
struct QNode* deQueue(struct Queue* q) 
{ 
	
	if (q->front == NULL) 
		return NULL; 

	struct QNode* temp = q->front; 
	free(temp); 

	q->front = q->front->next; 

	if (q->front == NULL) 
		q->rear = NULL; 
	return (temp); 
} 

// Driver Program to test anove functions 
int main() 
{ 
	struct Queue* q = createQueue(); 
	enQueue(q, 10); 
	enQueue(q, 20); 
	deQueue(q); 
	deQueue(q); 
	enQueue(q, 30); 
	enQueue(q, 40); 
	enQueue(q, 50); 
	struct QNode* n = deQueue(q); 
	if (n != NULL) 
		printf("Dequeued item is %d", n->key); 
	return 0; 
} 
*/
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

void insert(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   printf("\nInsertion is Success!!!\n");
}
void del()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}
void display()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL\n",temp->data);
   }
}
int main()
{
   int choice, value;
   //clrscr();
   printf("\n Linear Queue Implementation using Linked List \n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 insert(value);
		 break;
	 case 2: del(); break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
   return 0;
}
