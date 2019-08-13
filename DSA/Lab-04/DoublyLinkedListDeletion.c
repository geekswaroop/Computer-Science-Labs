/*
Write a program to delete a node from a given doubly linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
void deleteNode(struct Node** head_ref, struct Node* del)
{
	if(del == NULL || *head_ref == NULL)
		return;
	//Node to be deleted is the head node
	if(del == *head_ref)
	{
		*head_ref = del->next;
	}
	if(del->next!=NULL)
	{
		del->next->prev = del->prev;
	}
	if(del->prev!= NULL)
	{
		del->prev->next = del->next;
	}

	free(del);
}
void deleteNodeAtGivenPos(struct Node** head_ref, int n) 
{ 
	/* if list in NULL or invalid position is given */
	if (*head_ref == NULL || n <= 0) 
		return; 

	struct Node* current = *head_ref; 
	int i; 

	/* traverse up to the node at position 'n' from 
	the beginning */
	for (int i = 1; current != NULL && i < n; i++) 
		current = current->next; 

	/* if 'n' is greater than the number of nodes 
	in the doubly linked list */
	if (current == NULL) 
		return; 

	/* delete the node pointed to by 'current' */
	deleteNode(head_ref, current); 
} 

void push(struct Node** head_ref, int new_data) 
{ 
   
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  

    new_node->data = new_data; 

    new_node->prev = NULL; 

    new_node->next = (*head_ref); 

    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
 
    (*head_ref) = new_node; 
} 

void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
    printf("\n");
} 

int main() 
{ 

    struct Node* head = NULL; 
  

    push(&head, 2); 
    push(&head, 4); 
    push(&head, 8); 
    push(&head, 10); 
  
    printf("\n Original Linked list "); 
    printList(head); 
  

    deleteNodeAtGivenPos(&head, 2);
        printList(head);
    deleteNodeAtGivenPos(&head,3);
    printList(head);
  
    printf("\n Modified Linked list "); 
    printList(head); 
  
    getchar(); 
} 



