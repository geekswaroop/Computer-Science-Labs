
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
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

	// Count the number of nodes in loop 
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
	int i,n,temp,pos;
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
	struct Node* end=head;
	while(end->next!=NULL)
	{
		end = end->next;
	}
	printf("Please enter the position from the head where you want to create the loop\n");
	scanf("%d", &pos);
	temp = pos;
	struct Node* start_2 = head;

	while(temp--)
	{
		start_2 = start_2->next;
	}

	/* Create a loop for testing */
	
	detectAndRemoveLoop(head); 
	struct Node* start_3 = head;
	/*for(i=0;i<pos;i++)
	{
		printf("%d ", start_3->data);
		start_3 = start_3->next;
	}*/
	cout << "Linked List after removing loop \n"; 
	printList(head); 
	return 0; 
} 


