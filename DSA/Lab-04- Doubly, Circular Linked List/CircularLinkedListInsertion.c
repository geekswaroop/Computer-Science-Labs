/*Program to insert a node and traverse the list*/

#include<stdio.h> 
#include<stdlib.h> 
  

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 

void push(struct Node **head_ref, int data) 
{ 
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node)); 
    struct Node *temp = *head_ref; 
    ptr1->data = data; 
    ptr1->next = *head_ref; 
  
    
    if (*head_ref != NULL) 
    { 
        while (temp->next != *head_ref) 
            temp = temp->next; 
        temp->next = ptr1; 
    } 
    else
        ptr1->next = ptr1;
  
    *head_ref = ptr1; 
} 
  

void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    if (head != NULL) 
    { 
        do
        { 
            printf("%d ", temp->data); 
            temp = temp->next; 
        } 
        while (temp != head); 
    } 
    printf("\n");
} 
  
int main() 
{ 

    struct Node *head = NULL; 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
  
    printList(head); 
  
    return 0; 
} 