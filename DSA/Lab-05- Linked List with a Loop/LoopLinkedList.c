// write a program to find the loop in a linked list. Once found, break the loop at any given key. 
// We will be using Floyd's cycle finding algorithm
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node* node)
{	node = node->next;
	while(node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));
	new_node->data=new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

int detectLoop(struct Node* list)
{
	struct Node* slow_p = list;
	struct Node* fast_p = list;

	while(slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p == fast_p)
		{
			printf("Loop Found!\n");
			printf("Loop starting at key = %d\n", slow_p->data);
			return 1;
		}
	}
	return 0;
}

int main()
{
	struct Node* head = NULL;
	push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
              
    /* Create a loop for testing */
    head->next->next->next->next = head; 
    detectLoop(head); 
  
    return 0; 

}


