#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
// A structure to represent a stack 
struct StackNode { 
    int data; 
    struct StackNode* next; 
}; 

struct StackNode* newNode(int data)
{
	struct StackNode* stackNode = (struct StackNode*)(malloc(sizeof(stackNode)));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}
int isEmpty(struct StackNode* root)
{
	return !root;
}
void push(struct StackNode** root, int data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	stackNode->data = data;
	*root = stackNode;
}
int pop(struct StackNode** root)
{	
	if (isEmpty(*root)) 
        return INT_MIN; 
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data; 
	free(temp);
	return popped;
}
int peek(struct StackNode* root) 
{ 
    if (isEmpty(root)) 
        return INT_MIN; 
    return root->data; 
} 
void printStack(struct StackNode* root)
{
	while(root!=NULL)
	{
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}
int main() 
{ 
    int i,j,k,n,choice,temp;
	printf("Enter the size of the stack you want to create: \n");
	scanf("%d", &n);
   	struct StackNode* root = NULL; 
    printf("Enter the %d elements you want to push to the stack now: \n", n);
    while(n--)
    { 	
    	scanf("%d", &temp);
    	push(&root, temp);
	}
    printf("Your stack now is: \n");
    printStack(root);
    printf("You have 3 choices now! \n");
	printf("Press 1 to push a number to the stack\n");
	printf("Press 2 to pop the top-most element\n");
	printf("Press 3 to peek at the top element \n");
  	scanf("%d", &choice);
    switch(choice)
	{	
		case 1:
		{	
			printf("Enter the number you want to push: \n");
			int temp;
			scanf("%d", &temp);
			push(&root, temp);
			printStack(root);
			break;
		}
		case 2:
		{	pop(&root);
			printf("Your Modified Stack after popping is: \n");
			printStack(root);
			break;
		}
		case 3:
		{
			printf("The topmost element of the stack is: \n");
			printf("%d", peek(root));
			break;
		}
		default:
		{
			printf("Wrong Choice! Please try again\n");
		}
	}
  
} 
