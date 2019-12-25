/*
This problem is also known as tortoise and hare algorithm. Basically, 
you have twopointers fast and slow and they move with different speed 
i.e. fast moves 2 notes in each iteration and slow moves one node. If 
linked list contains cycle then at some point in time, both fast and 
slow pointer will meet and point to the same node, if this didn't happen 
and one of the pointer reaches the end of linked list means linked list 
doesn't contain any loop.
*/

#include<iostream>
using namespace std; 

/* Link list node */
struct Node { 
public: 
	int data; 
	Node* next; 
}; 

void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

int detectloop(Node* list) 
{ 
	Node *slow_p = list, *fast_p = list; 

	while (slow_p && fast_p && fast_p->next) { 
		slow_p = slow_p->next; 
		fast_p = fast_p->next->next; 
		if (slow_p == fast_p) { 
			cout << "Found Loop"; 
			return 1; 
		} 
	} 
	return 0; 
} 

/* Driver code*/
int main() 
{ 
	/* Start with the empty list */
	Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 10); 

	/* Create a loop for testing */
	head->next->next->next->next = head; 
	detectloop(head); 

	return 0; 
} 
