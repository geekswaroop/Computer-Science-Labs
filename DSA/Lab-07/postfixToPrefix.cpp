// CPP Program to convert postfix to prefix 
#include <iostream> 
#include <stack> 
using namespace std; 

// function to check if character is operator or not 
bool isOperator(char x) 
{ 
	switch (x) { 
	case '+': 
	case '-': 
	case '/': 
	case '*': 
		return true; 
	} 
	return false; 
} 

string postToPre(string post_exp) 
{ 
	stack<string> s; 

	int length = post_exp.size(); 

	for (int i = 0; i < length; i++) { 

		if (isOperator(post_exp[i])) { 

			string op1 = s.top(); 
			s.pop(); 
			string op2 = s.top(); 
			s.pop(); 

			string temp = post_exp[i] + op2 + op1; 

			s.push(temp); 
		} 

		else{

			s.push(string(1, post_exp[i])); 
		}

		} 
	 

	return s.top(); 
} 

int main() 
{ 
	string post_exp; 
	cout << "Enter the PostFix String you want to convert to Prefix"<<endl;
	cin>>post_exp;
	cout << "Prefix : " << postToPre(post_exp)<<endl; 
	return 0; 
} 
