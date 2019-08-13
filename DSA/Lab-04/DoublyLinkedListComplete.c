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
int main()
{
    struct Node* head=NULL;
   // head = (struct Node*)(malloc(sizeof(struct Node)));
    printf("Hello there! Enter the number of elements in the doubly linked list\n");
    int n;
    scanf("%d", &n);
    printf("Enter the %d elements now \n", n);
    while(n--)
    {
        int temp;
        scanf("%d", &temp);
        push(&head, temp);
    }
    printf("Your Entered List is: \n");
    printList(head);

    printf("You have 3 choices now! \n");
    printf("Press 1 to append a number at the end\n");
    printf("Press 2 to push a number at the beginning\n");
    printf("Press 3 to delete a number at a given position \n");

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
            printf("Enter the position you want to delete\n");
            int temp;
            scanf("%d", &temp);
            deleteNodeAtGivenPos(&head,temp);
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