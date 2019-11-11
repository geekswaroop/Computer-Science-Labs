/*
Write a program to insert new node and traverse the entire doubly linked list
Insert the node in the following ways
1) Insert at head
2) Insert at end
3) Insert after a given node
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
void printList(struct Node* node)  
{  
    struct Node* last;  
    printf("\nTraversal in forward direction \n");  
    while (node != NULL) {  
        printf(" %d ", node->data);  
        last = node;  
        node = node->next;  
    }  
  
    printf("\nTraversal in reverse direction \n");  
    while (last != NULL) {  
        printf(" %d ", last->data);  
        last = last->prev;  
    }  
    printf("\n");
}  
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->prev = NULL;
	new_node->next = *head_ref;
	if ((*head_ref) != NULL) 
       (*head_ref)->prev = new_node; 
   *head_ref= new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL\n"); 
        return; 
    } 
    new_node->data = new_data; 
	new_node->prev = prev_node;
	new_node->next = prev_node->next;
	prev_node->next->prev = new_node;
	prev_node->next = new_node;
}

void  append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    struct Node* last = *head_ref; /* used in step 5*/
  
    
    new_node->data = new_data; 

    new_node->next = NULL; 
  
   //Checking if empty linked list is passed
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
    //traversing the DLL and finding the last node
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = new_node; 
    new_node->prev = last; 
    return; 
}

int main()
{

    struct Node* head = NULL;  
    push(&head, 7);  
  
    push(&head, 1);  
  
    push(&head, 4);  

    printList(head);
    // Insert 8, before 1. So linked list becomes 4->8->1->7->NULL  
    
  	append(&head, 8);
  	printList(head);
   	insertAfter(head->next, 2); 
    printList(head);  
  
    getchar();  
    return 0;  
}