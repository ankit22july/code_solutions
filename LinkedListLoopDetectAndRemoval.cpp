/*
Let slow and fast meet at some point after Floyd’s Cycle finding algorithm.

Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time
       
From above equation, we can conclude below 
 m + k = (x-2y)*n

Which means m+k is a multiple of n. 

So if we start moving both pointers again at same speed such that one pointer 
(say slow) begins from head node of linked list and other pointer (say fast) 
begins from meeting point. When slow pointer reaches beginning of loop (has 
made m steps), fast pointer would have made also moved m steps as they are 
now moving same pace. Since m+k is a multiple of n and fast starts from k, 
they would meet at the beginning. Can they meet before also? No because slow
pointer enters the cycle first time after m steps
*/
#include <iostream> 
using namespace std; 

struct Node { 
	int key; 
	struct Node* next; 
}; 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to print a linked list 
void printList(Node* head) 
{ 
	while (head != NULL) { 
		cout << head->key << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 

// Function to detect and remove loop 
// in a linked list that may contain loop 
void detectAndRemoveLoop(Node* head) 
{ 
	// If list is empty or has only one node 
	// without loop 
	if (head == NULL || head->next == NULL) 
		return; 

	Node *slow = head, *fast = head; 

	// Move slow and fast 1 and 2 steps 
	// ahead respectively. 
	slow = slow->next; 
	fast = fast->next->next; 

	// Search for loop using slow and 
	// fast pointers 
	while (fast && fast->next) { 
		if (slow == fast) 
			break; 
		slow = slow->next; 
		fast = fast->next->next; 
	} 

	/* If loop exists */
	if (slow == fast) { 
		slow = head; 
		while (slow->next != fast->next) { 
			slow = slow->next; 
			fast = fast->next; 
		} 

		/* since fast->next is the looping point */
		fast->next = NULL; /* remove loop */
	} 
} 

/* Driver program to test above function*/
int main() 
{ 
	Node* head = newNode(50); 
	head->next = head; 
	head->next = newNode(20); 
	head->next->next = newNode(15); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(10); 

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next; 

	detectAndRemoveLoop(head); 

	printf("Linked List after removing loop \n"); 
	printList(head); 

	return 0; 
} 
