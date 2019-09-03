#include <stdio.h>
#include <limits.h> 
#include <stdlib.h>
#include <string.h>

struct StackNode { 
    char data; 
    struct StackNode* next; 
}; 
void strReverse(char a [], char reverse[])
{
	int begin, end, count = 0;
	while (a[count] != '\0')
      count++;
 
   end = count - 1;
 
   for (begin = 0; begin < count; begin++) {
      reverse[begin] = a[end];
      end--;
   }
 
   reverse[begin] = '\0';
}
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
void infixToPostfix(char a[], struct StackNode* stack, char ans[])
{	
	int i,j,k;
	int ln = strlen(a);
	//char ans[ln+1];
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
	//printf("%s\n", ans);
}
void preprocess(char exp[],char reverse1[],int ln)
{
	int i,j,k;
	//ln = strlen(reverse);
	for(i=0;i<ln;i++)
	{
		if(exp[i]==')')
			reverse1[i]=='(';
		else if(exp[i]=='(')
			reverse1[i]==')';
		else
			reverse1[i]=exp[i];
	}
}
int main()
{	
	int i,j,k;
	char exp[100];
	struct StackNode* stack = NULL; 
	printf("Enter the Infix Expression you want to convert to prefix : \n");
	scanf("%s", exp);
	int len = strlen(exp);
	char reverse[100],ans[100],finalAns[100],reverse1[100];
	for(i=0;i<len;i++)
	{
		if(exp[i]==')')
		{
			exp[i]='(';
			continue;
		}
		if(exp[i]=='(')
		{
			exp[i]=')';
			continue;
		}
	}
	//preprocess(exp,reverse1,len);
	//printf("%s \n", exp);
	strReverse(exp,reverse);
	//printf("%s \n", reverse);
	infixToPostfix(reverse,stack, ans);
	strReverse(ans,finalAns);
	printf("%s\n", finalAns);
//(a-b/c)*(a/k-l)

}