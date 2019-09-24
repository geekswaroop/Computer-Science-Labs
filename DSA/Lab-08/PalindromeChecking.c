/*#include <bits/stdc++.h> 
using namespace std; 

bool isPalindrome(string exp)
{
	int i;
	stack<char>s;
	if(exp.size()%2)
	{
	for(i=0;i<(exp.size())/2;i++)
	{
		s.push(exp[i]);
	}
	for(i=(exp.size())/2;i<exp.size();i++)
	{
		if(exp[i]==s.top())
		{	s.pop();
			continue;
		}
		else
			return 0;
	}
	return 1;
}
else
{
for(i=0;i<(exp.size())/2;i++)
	{
		s.push(exp[i]);
	}
	for(i=(exp.size())/2+1;i<=exp.size();i++)
	{
		if(exp[i]==s.top())
		{	s.pop();
			continue;
		}
		else
			return 0;
	}
	return 1;
}
}

int main()
{
	string expr;
	cout<<"Enter the palindrome string you want to check"<<endl;
	cin>>expr;
	if(isPalindrome(expr))
	{
		cout<<"Given string is a palindrome!"<<endl;
	}
	else
	{
		cout<<"Given string is not a palindrome!"<<endl;
	}
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
/* push a character into stack */
void push(char a)
{
      top++;
      stack[top]  =  a;
}
/* delete an element in stack */
void pop()
{
      top--;
}
int main()
{
      int i, cho;
      char s[MAX], b;
      printf("\tMENU");
      printf("\n---------------------------\n");
      printf("1.Check string is palindrome.\n2.Exit\n");
      printf("---------------------------\n");
      while (1)
      {
            printf("Choose operation : ");
            scanf("%d", &cho);
            switch (cho)
            {
                  case 1:
                        printf("\nEnter string : ");
                        scanf("%s", s);
                        for (i = 0;s[i] != '\0';i++)
                        {
                              b = s[i];
                              push(b);
                        }
                        for (i = 0;i < (strlen(s) / 2);i++)
                        {
                              if (stack[top] == stack[front])
                              {
                                    pop();
                                    front++;
                              }
                              else
                              {
                                    printf("'%s' is not palindrome.\n\n", s);
                                    break;
                              }
                        }
                        if ((strlen(s) / 2)==  front)
                              printf("'%s' is palindrome.\n\n",  s);
                        front  =  0;
                        top  =  -1;
                        break;
                  case 2:
                        exit(0);
                  default: printf("Invalid operation \n");
            }
      }
      return 0;
}