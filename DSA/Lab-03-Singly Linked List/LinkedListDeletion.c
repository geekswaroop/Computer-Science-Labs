//program to delete a linked list

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
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));
	new_node->data=new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void deleteNode(struct Node** head_ref, int key)
{
	struct Node* temp=NULL;
	struct Node* prev=NULL;
	temp = *head_ref;

	/*if(temp->data == key && temp!=NULL)
	{
		*head_ref = temp->next;    
        free(temp);               // free old head 
        return; 
	}*/
	while(temp->data != key && temp!=NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL)
		return;
	prev->next = temp->next;
	free(temp);
}

int main()
{
	//driver function to test the deletion

    struct Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
  
    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 1); 
    puts("\nLinked List after Deletion of 1: "); 
    printList(head); 
    return 0; 
}