//Program to create a simple linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node* node)
{
	while(node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}
int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	//allocate memory
	head = (struct Node*)(malloc(sizeof(struct Node)));
	second = (struct Node*)(malloc(sizeof(struct Node)));
	third = (struct Node*)(malloc(sizeof(struct Node)));

	int a, b,c;
	printf("Enter 3 numbers that are part of the linked list\n");
	scanf("%d %d %d", &a,&b,&c);
	//Assign the data

	head->data = a;
	head->next=second;

	second->data = b;
	second->next = third;

	third->data=c;
	third->next=NULL;

	printList(head);
	return 0;
}
	
