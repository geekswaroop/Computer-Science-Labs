/*Write a program to delete a node in circular linked list*/ 
#include <stdio.h> 
#include <stdlib.h> 


struct Node { 
	int data; 
	struct Node* next; 
}; 

void push(struct Node** head_ref, int data) 
{ 

	struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
	ptr1->data = data; 
	ptr1->next = *head_ref; 

	if (*head_ref != NULL) { 
		
		struct Node* temp = *head_ref; 
		while (temp->next != *head_ref) 
			temp = temp->next; 
		temp->next = ptr1; 
	} 
	else
		ptr1->next = ptr1; 

	*head_ref = ptr1; 
} 


void printList(struct Node* head) 
{ 
	struct Node* temp = head; 
	if (head != NULL) { 
		do { 
			printf("%d ", temp->data); 
			temp = temp->next; 
		} while (temp != head); 
	} 

	printf("\n"); 
} 


void deleteNode(struct Node **head, int key)
{
if (*head == NULL) {
return;
}

Node *cur = *head;
Node *prev = NULL;

while(cur->data != key) {
if (cur->next == *head) {
break;
}

prev = cur;
cur = cur->next;
}

// if match is found
if (cur->data == key) {
// key matched the head node
if (cur == *head) {
prev = *head;
// get the prev node to the head node, traverse whole list
while (prev->next != *head)
{
prev = prev->next;
}

// one element list, so head will become NULL (empty list)
if (cur == cur->next) {
*head = NULL;
}
else
{
*head = cur->next;
}
}
prev->next = cur->next;

free(cur);
}

}
int main() 
{ 

	struct Node* head = NULL; 


	push(&head, 2); 
	push(&head, 5); 
	push(&head, 7); 
	push(&head, 8); 
	push(&head, 10); 

	printf("List Before Deletion: "); 
	printList(head); 

	deleteNode(&head, 10); 

	printf("List After Deletion: "); 
	printList(head); 

	return 0; 
} 
