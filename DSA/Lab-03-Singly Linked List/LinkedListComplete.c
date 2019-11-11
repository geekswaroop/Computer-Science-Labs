

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
	struct Node* head;
	head = (struct Node*)(malloc(sizeof(struct Node)));
	printf("Hello there! Enter the number of elements in the linked list\n");
	int n;
	scanf("%d", &n);
	printf("Enter the %d elements now \n", n);
	while(n--)
	{
		int temp;
		scanf("%d", &temp);
		append(&head, temp);
	}
	printf("Your Entered List is: \n");
	printList(head);

	printf("You have 3 choices now! \n");
	printf("Press 1 to append a number at the end\n");
	printf("Press 2 to push a number at the beginning\n");
	printf("Press 3 to delete a number \n");

	int choice;
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
		{	
			printf("Enter the number you want to append\n");
			int temp;
			scanf("%d", &temp);
			append(&head,temp);
			printf("Your Modified Linked List is: \n");
			printList(head);
			break;
		}
		case 2:
		{
			printf("Enter the number you want to push at the beginning\n");
			int temp;
			scanf("%d", &temp);
			push(&head,temp);
			printf("Your Modified Linked List is: \n");
			printList(head);
			break;
		}
		case 3:
		{
			printf("Enter the number you want to delete\n");
			int temp;
			scanf("%d", &temp);
			deleteNode(&head,temp);
			printf("Your Modified Linked List is: \n");
			printList(head);
			break;
		}
		default:
		{
			printf("Wrong Choice! Please try again\n");
		}
	}

	return 0;
}