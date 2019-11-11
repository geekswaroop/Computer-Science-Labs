#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
struct Node  
{ 
    int data; 
    struct Node *left; 
    struct Node *right; 
}; 
  
/*int root_value,choice2,value;
	char choice,choice1;
	printf("Enter the Root Node value\n");
	scanf("%d", &root_value);
	struct Node *root = newNode(root_value);
	struct Node* temp = root;
	printf("Do you want to enter any more nodes?(Y/N)\n");
	scanf("%c", &choice);
	if(choice=='Y')
{ 
	while(1)
	{	
		printf("Please enter the node value you want to add:\n");
		scanf("%d", &value);
		while(temp!=NULL)
		{
			printf("Do you want to enter the value to the Left or Right(L/R) of %d?\n", temp->data);
			scanf("%c", &choice1);
			if(choice1=='L')
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		temp->data = value;
		printf("Do you want to enter any more nodes?(Y/N)\n");
		scanf("%c", &choice);
		if(choice=='Y')
			continue;
		else
			break;
	}
}
	printPostorder(root);
struct Node* newNode(int data) 
{ 
  
  struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
  
  
  node->data = data; 
  
  
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} */
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  

    printPostorder(node->left); 
  

    printPostorder(node->right); 
  

    cout << node->data << " "; 
} 
 
 void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 

    printInorder(node->left); 
  

    cout << node->data << " "; 
  

    printInorder(node->right); 
} 
  

void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  

    cout << node->data << " "; 
  
    
    printPreorder(node->left);  
  
  
    printPreorder(node->right); 
}  
void deletDeepest(struct Node* root, 
                  struct Node* d_node) 
{ 
    queue<struct Node*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    struct Node* temp; 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == d_node) { 
                temp->right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 
  
/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key) 
{ 
    if (root == NULL) 
        return NULL; 
  
    if (root->left == NULL && root->right == NULL) { 
        if (root->key == key) 
            return NULL; 
        else
            return root; 
    } 
  
    queue<struct Node*> q; 
    q.push(root); 
  
    struct Node* temp; 
    struct Node* key_node = NULL; 
  
    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
  
        if (temp->key == key) 
            key_node = temp; 
  
        if (temp->left) 
            q.push(temp->left); 
  
        if (temp->right) 
            q.push(temp->right); 
    } 
  
    if (key_node != NULL) { 
        int x = temp->key; 
        deletDeepest(root, temp); 
        key_node->key = x; 
    } 
    return root; 
} 
int main()
{	
	int choice,i,j,value;
	printf("Hello! Please enter the root value of the Binary Tree you want to construct\n");
	scanf("%d", &value);
	struct Node *root = newNode(value);
	printf("You have 3 choices now\n");
	printf("1. Insertion of nodes\n");
	printf("2. Tree Traversals\n");
	printf("3. Deletion of Node\n");
	scanf("%c", &choice);
	switch(choice)
	{
		case 1:
		{
			buildTree();
			break;
		}
		case 2:
		{
			int choice2;
			printf("Which Traversal do you need?\n1. Postorder\n2. Preorder\n3. Inorder\n");
			scanf("%d", &choice2);
			if(choice==1)
				printPostorder(root);
			else if(choice==2)
				printPreorder(root);
			else
				printInorder(root);
			break;
		}
		case 3
	}
}