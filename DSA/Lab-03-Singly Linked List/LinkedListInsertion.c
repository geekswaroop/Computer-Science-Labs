//Program to insert nodes into LL in 3 different ways
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
	printf("\n");
}

//Inserting data at the head

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));
	new_node->data=new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
// Inserting data after a particular node
void inserAfter(struct Node* prev_node, int new_data)
{
	struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;

}

//Inserting the node at the end
void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));
	new_node->data = new_data;
	new_node->next = NULL;
	struct Node* last = *head_ref;
	while(last->next!=NULL)
	{
		last = last->next;
	}
	last->next = new_node;
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

	//Dummy initialisation to demonstrate the working of insertion
	head->data = 1;
	head->next = second;

	second->data=2;
	second->next = third;

	third->data = 3;
	third->next= NULL;

	//we will push now to the beginning of the list
	push(&head, 6);
	printList(head);

	//insert after a previous node, in this case, second
	inserAfter(second, 7);
	printList(head);

	//insert at the end
	append(&head, 9);
	printList(head);
}