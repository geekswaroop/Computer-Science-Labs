
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
//#include <conio.h>
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);

    if(x==-1)
  return NULL;

    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

void preorder(node *t)
{
  if(t!=NULL)
  {
    printf("  %d",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}
void inorder(node *t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("  %d",t->data);
    inorder(t->right);
  }
}
void postorder(node *t)
{
  if(t!=NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("  %d",t->data);
  }
}
struct node* minvalue(struct node *node) {
  if(node == NULL)
    return NULL;

  /* Go to the left sub tree to find the min element */
  if(node->left)
    return minvalue(node->left);
  else
    return node;                  
}

/* Function for delete node from the Tree */
struct node* del(struct node *leaf, int key) {
	struct node* temp1 = leaf;
	if(leaf == NULL)
		printf("Element Not Found!\n");
	else if(key < leaf->data)
		leaf->left = del(leaf->left, key);
	else if(key > leaf->data)
		leaf->right = del(leaf->right, key);
	else {
		if(leaf->right && leaf->left) {

			/* Replace with minimum element in the right sub tree */
			struct node* temp = minvalue(leaf->right);
			leaf->data = temp->data;

			/* Delete that node */
			leaf->right = del(leaf->right,temp->data);
		}	
		else {
			/* If there is only one or zero children then directly remove it from the tree and connect its parent to its child */
			struct node* temp = leaf;
			if(leaf->left == NULL) 
				leaf = leaf->right;
			else if(leaf->right == NULL)
				leaf = leaf->left;
			free(temp);
			printf("Data delete successfully!\n");
		}
	}	
	inorder(temp1);								
}

int main()
{
  node *root;
  //clrscr();
  root=create();
  printf("\nThe preorder traversal of tree is: ");
  preorder(root);
  printf("\nThe inorder traversal of tree is: ");
  inorder(root);
  printf("\nThe postorder traversal of tree is: ");
  postorder(root);
  printf("Enter the node you want to delete:\n");
  int key;
  scanf("%d",&key);
  del(root, key);
 
  //getch();
  return 0;
}