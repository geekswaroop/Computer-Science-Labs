#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
 
# define MAXSTACK 100        /* for max size of stack */
# define POSTFIXSIZE 100
// A structure to represent a stack 
struct StackNode { 
    char data; 
    struct StackNode* next; 
}; 

struct StackNode* newNode(char data)
{
	struct StackNode* stackNode = (struct StackNode*)(malloc(sizeof(stackNode)));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}
char isEmpty(struct StackNode* root)
{
	return !root;
}
void push(struct StackNode** root, char data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	stackNode->data = data;
	*root = stackNode;
}
char pop(struct StackNode** root)
{	
	if (isEmpty(*root)) 
        return INT_MIN; 
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data; 
	free(temp);
	return popped;
}
char peek(struct StackNode* root) 
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
void postfixEvaluation(char a[], struct StackNode** root)
{
	int i,val;
	char ch,A,B;
	for(i=0;a[i]!='!';i++)
	{
		ch = a[i];
		if(ch>='0'&&ch<='9')
		{
			push(root, (ch-'0'));
		}
		else if(ch=='+' || ch=='*' || ch=='/' || ch=='-')
		{	
			A = pop(root);
			B = pop(root);
			//ch =
			switch(ch)
			{
				case '+':
				{
					val = A+B;
					break;
				}
				case '-':
				{
					val = A-B;
					break;
				}
				case '*':
				{
					val = A*B;
					break;
				}
				case '/':
				{
					val = A/B;
					break;
				}

			}
			push(root, val);

			} 
		}
		printf("Final Evaluated Expression is: %d\n", pop(root));
}
int main()
{	
	struct StackNode* root = NULL; 
	int i ;
	printf("ASSUMPTION: There are only four operators(*, /, +, -) in an expression and operand is single digit only.\n");
	printf( " \nEnter postfix expression,\npress right parenthesis '!' for end expression : ");
	char postfix[POSTFIXSIZE];
	/* take input of postfix expression from user */

	for (i = 0 ; i <= POSTFIXSIZE - 1 ; i++)
	{
		scanf("%c", &postfix[i]);

		if ( postfix[i] == '!' ) /* is there any way to eliminate this if */
		{ break; } /* and break statement */
	}

	/* call function to evaluate postfix expression */

	postfixEvaluation(postfix,&root);
	
	return 0;
}