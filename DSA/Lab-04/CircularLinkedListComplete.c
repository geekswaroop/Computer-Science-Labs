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
struct Node *addToEmpty(struct Node *last, int data) 
{ 
    // This function is only for empty list 
    if (last != NULL) 
    return last; 

    // Creating a node dynamically. 
    struct Node *temp = 
        (struct Node*)malloc(sizeof(struct Node)); 

    // Assigning the data. 
    temp -> data = data; 
    last = temp; 

    // Creating the link. 
    last -> next = last; 

    return last; 
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
    struct Node* head=NULL;
   // head = (struct Node*)(malloc(sizeof(struct Node)));
    printf("Hello there! Enter the number of elements in the circular linked list\n");
    int n,temp;
    scanf("%d", &n);
    printf("Enter the %d elements now \n", n);
    //scanf("%d", &temp);
    //addToEmpty(head, temp);
    //int t = n-1;
    while(n--)
    {
        int temp;
        scanf("%d", &temp);
        push(&head, temp);
    }
    printf("Your Entered List is: \n");
    printList(head);

    printf("You have 2 choices now! \n");
    printf("Press 1 to push a number at the end\n");
    printf("Press 2 to delete a number key\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {   
            printf("Enter the number you want to push\n");
            int temp;
            scanf("%d", &temp);
            push(&head,temp);
            printf("Your Modified Linked List is: \n");
            printList(head);
            break;
        }
        case 2:
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


