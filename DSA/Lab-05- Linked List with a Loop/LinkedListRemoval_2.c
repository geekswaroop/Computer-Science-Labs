


#include <bits/stdc++.h> 
using namespace std; 


struct Node { 
	int data; 
	struct Node* next; 
}; 


void removeLoop(struct Node*, struct Node*); 

int detectAndRemoveLoop(struct Node* list) 
{ 
	struct Node *slow_p = list, *fast_p = list; 


	while (slow_p && fast_p && fast_p->next) { 
		slow_p = slow_p->next; 
		fast_p = fast_p->next->next; 

	
		if (slow_p == fast_p) { 
			//printf("Loop found at %d key!\n", slow_p->data);
			removeLoop(slow_p, list); 

			return 1; 
		} 
	} 

	return 0; 
} 

void removeLoop(struct Node* loop_node, struct Node* head) 
{ 
	struct Node* ptr1 = loop_node; 
	struct Node* ptr2 = loop_node; 

	unsigned int k = 1, i; 
	while (ptr1->next != ptr2) { 
		ptr1 = ptr1->next; 
		k++; 
	} 

	ptr1 = head; 

	ptr2 = head; 
	for (i = 0; i < k; i++) 
		ptr2 = ptr2->next; 

	while (ptr2 != ptr1) { 
		ptr1 = ptr1->next; 
		ptr2 = ptr2->next; 
	} 

	while (ptr2->next != ptr1) 
		ptr2 = ptr2->next; 

	ptr2->next = NULL; 
} 

/* Function to print linked list */
void printList(struct Node* node) 
{ 

	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

struct Node* newNode(int key) 
{ 
	struct Node* temp = new Node(); 
	temp->data = key; 
	temp->next = NULL; 
	return temp; 
} 

int main() 
{ 
	printf("Please enter the total number of nodes in the linked list\n");
	int i,n,temp,pos1,pos2;
	scanf("%d", &n);
	printf("Please enter the elements of the linked list\n");
	scanf("%d", &temp);
	struct Node* head = newNode(temp);
	struct Node* start = head;
	for(i=1;i<n;i++)
	{
		scanf("%d", &temp);
		start->next = newNode(temp);
		start = start->next;
	}
	printf("Please enter the 2 positions from the head where you want to create the loop\n");
	scanf("%d %d", &pos1,&pos2);
	temp = pos1;
	struct Node* start_2 = head;
	while(temp--)
	{
		start_2 = start_2->next;
	}
	temp = pos2;
	struct Node* start_3 = head;

	while(temp--)
	{
		start_3 = start_3->next;
	}

	/* Create a loop for testing */
	struct Node* temp1 = start_2;
	start_2 = start_3; 

	detectAndRemoveLoop(head); 

	cout << "Linked List after removing loop \n"; 
	printList(head); 
	printf("\n");
	while(temp1!=NULL)
	{
		printf("%d ", temp1->data);
		temp1 = temp1->next;
	}
	return 0; 
} 

