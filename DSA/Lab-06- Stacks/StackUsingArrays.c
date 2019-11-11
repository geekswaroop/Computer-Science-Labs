#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity-1;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}
void push(struct Stack* stack, int new_item)
{
	if(isFull(stack))
		return;
	else
	{
		stack->array[++stack->top] = new_item;
	}
}
int pop(struct Stack* stack)
{
	return stack->array[--stack->top];
}
int peek(struct Stack* stack)
{
	return stack->array[stack->top];
}
void printStackFull(struct Stack* stack)
{
	int i;
	for(i=0;i<stack->capacity;i++)
	{
		printf("%d ", stack->array[i]);
	}
	printf("\n");
}
void printStackPop(struct Stack* stack)
{
	int i;
	for(i=0;i<stack->top;i++)
	{
		printf("%d ", stack->array[i]);
	}
	printf("\n");
}

int main() 
{ 	
	int i,j,k,capacity,choice,temp;
	printf("Enter the size of the stack you want to create: \n");
	scanf("%d", &capacity);
    struct Stack* stack = createStack(capacity);
    printf("Enter the %d elements you want to push to the stack now: \n", capacity);
    for(i=0;i<capacity;i++)
    {
    	scanf("%d", &temp);
    	push(stack, temp);
    } 
    printf("Your stack now is: \n");
    printStackFull(stack);
    printf("You have 3 choices now! \n");
	//printf("Press 1 to push a number to the stack\n");
	printf("Press 2 to pop the top-most element\n");
	printf("Press 3 to peek at the top element \n");
  	scanf("%d", &choice);
    switch(choice)
	{
		case 2:
		{
			printf("Your Modified Stack after popping is: \n");
			printStackPop(stack);
			break;
		}
		case 3:
		{
			printf("The topmost element of the stack is: \n");
			printf("%d", stack->array[stack->top]);
			break;
		}
		default:
		{
			printf("Wrong Choice! Please try again\n");
		}
	}
  
    return 0; 
} 