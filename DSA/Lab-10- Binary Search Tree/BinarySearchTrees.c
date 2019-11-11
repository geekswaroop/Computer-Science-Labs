#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node* left;
	struct node* right;
}*root;

void find(int item, struct node **par, struct node **loc)
{
	struct node *ptr, *ptrsave;
	if(root == NULL)
	{
		*loc = NULL;
		*par = NULL;
		return;
	}
	if(item == root->info)
	{
		*loc = root;
		*par = NULL;
		return;
	}
	if(item < root->info)
	{
		ptr = root->left;
	}
	else
	{
		ptr = root->right;
		ptrsave = root;
	}
	while(ptr!=NULL)
	{
		if(item == ptr->info)
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if(item < ptr->info)
		{
			ptr = ptr->left;
		}
		else
		{
			ptr = ptr->right;
		}
	}
	*loc = NULL;
	*par = ptrsave;
}
void insert(int item)
{
	struct node *tmp, *parent, *location;
	find(item , &parent, &location);
	if(location != NULL)
	{
		printf("Element already present!\n");
		return;
	} 
	tmp = (struct node*)(malloc(sizeof(struct node)));
	tmp->info = item;
	tmp->left = NULL;
	tmp->right = NULL;

	if(parent == NULL)
	{
		root = tmp;
	}
	else
	{
		if(item < parent->info)
		{
			parent->left = tmp;
		}
		else
		{
			parent->right = tmp;
		}
	}
}
void case_a(struct node* loc, struct node* par)
{
	if(par== NULL)
	{
		//printf("No tree present!\n");
		//return;
		root = NULL;
	}
	else
	{
		if(par->left == loc)
		{
			par->left = NULL;
		}
		else
		{
			par->right = NULL;
		}
	}
}
void case_b(struct node* loc, struct node* par)
{
	struct node* child;
	if(loc->left != NULL)
	{
		child = loc->left;
	}
	else
	{
		child = loc->right;
	}
	if(par==NULL)
	{
		root = child;
	}
	else
	{
		if(loc == par->left)
		{
			par->left = child;
		}
		else
		{
			par->right = child;
		}
	}
}
void case_c(struct node *par,struct node *loc)
{
    struct node *ptr,*ptrsave,*suc,*parsuc;

    /*Find inorder successor and its parent*/
    ptrsave=loc;
    ptr=loc->right;
    while(ptr->left!=NULL)
    {
        ptrsave=ptr;
        ptr=ptr->left;
    }
    suc=ptr;
    parsuc=ptrsave;

    if(suc->left==NULL && suc->right==NULL)
        case_a(parsuc,suc);
    else
        case_b(parsuc,suc);

    if(par==NULL) /*if item to be deleted is root node */
        root=suc;
    else
        if(loc==par->left)
            par->left=suc;
        else
            par->right=suc;

    suc->left=loc->left;
    suc->right=loc->right;
}
void del(int item)
{	
	struct node *location, *parent;
	if(root == NULL)
	{
		printf("Tree Empty\n");
		return;
	}
	find(item, &location, &parent);
	if(location == NULL)
	{
		printf("Item not present in the tree\n");
		return;
	}
	if(location->left == NULL && location->right == NULL)
	{
		case_a(parent,location);
	}
	if(location->left!=NULL && location->right==NULL)
	{
		case_b(parent, location);
	}
	if(location->left==NULL && location->right!=NULL)
	{
		case_b(parent, location);
	}
	if(location->left!=NULL && location->right!=NULL)
	{
		case_c(parent,location);
	}
	free(location);

}
void preorder(struct node* ptr)
{
	if(ptr == NULL)
		return;
	printf("%d ", ptr->info);
	preorder(ptr->left);
	preorder(ptr->right);
	//printf("\n");
}
void inorder(struct node* ptr)
{
	if(ptr == NULL)
		return;
	
	inorder(ptr->left);
	printf("%d ", ptr->info);
	inorder(ptr->right);
	//printf("\n");
}
void postorder(struct node* ptr)
{
	if(ptr == NULL)
		return;
	
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d ", ptr->info);
	//printf("\n");
}

int main()
{	
	int choice, num;
	printf("You have 5 choices:\n");
	
	//int choice;
	root = NULL;

	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Quit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the number to be inserted\n");
				scanf("%d", &num);
				insert(num);
				break;
			}
			case 2:
			{	
				printf("Enter the element you want to delete\n");
				scanf("%d", &num);
				del(num);
				break;
			}
			case 3:
			{
				preorder(root);
				break;
			}
			case 4:
			{
				inorder(root);
				break;
			}
			case 5:
			{
				postorder(root);
				break;
			}
			case 6:
			{
				break;
			}
		}
		if(choice == 6)
			break;
	}
}
