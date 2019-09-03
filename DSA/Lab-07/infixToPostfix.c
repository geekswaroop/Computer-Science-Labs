#include <stdio.h>
#include <limits.h> 
#include <stdlib.h>
#include <string.h>
char exp[100];
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
int isEmpty(struct StackNode* root)
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
	char popped = temp->data; 
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
int prec(char a)
{
	if(a=='^')
		return 3;
	else if (a=='/' || a=='*')
		return 2;
	else if (a=='+' || a=='-')
		return 1;
	else
		return -1;
}
void infixToPostfix(char a[], struct StackNode* stack)
{	
	int i,j,k;
	int ln = strlen(a);
	char ans[ln+1];
	j=-1;
	for(i=0;i<ln;i++)
	{
		if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<= 'Z'))
			ans[++j] = a[i];
		else if (a[i]=='(')
			push(&stack,'(');
		else if (a[i]==')')
		{
			while(!isEmpty(stack) && peek(stack)!='(')
			{
				char c = peek(stack);
				ans[++j] = c;
				pop(&stack);
			}
			if(peek(stack)=='(')
			{
				char c = peek(stack);
				pop(&stack);
			}
		}
		else //operator is encountered
		{
			while(!isEmpty(stack) && prec(a[i])<=prec(peek(stack)))
			{
				char c = peek(stack);
				ans[++j] = c;
				pop(&stack);
			}

			push(&stack, a[i]);
		}


	}
	while(!isEmpty(stack))
	{
		char c = peek(stack);
		ans[++j] = c;
		pop(&stack);
	}
	printf("%s\n", ans);
}

int main()
{	
	struct StackNode* stack = NULL; 
	printf("Enter the Infix Expression you want to convert to postfix : \n");
	scanf("%s", exp);
	//reverse(exp,reverse);
	//preprocess(reverse)
	infixToPostfix(exp,stack);
}