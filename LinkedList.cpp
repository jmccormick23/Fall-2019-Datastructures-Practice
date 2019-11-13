//testing
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

void createNode(Node<int>* current_node, int data) {
	Node<int>* new_node = NULL; // creates a pointer to a NODE, then sets that to NULL
	new_node = new Node<int>(); // Actually creates the a new NODE

	if (current_node->next == NULL)
		current_node->next = new_node; //links the head NODE to the currently created NODE
	else {
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	new_node->data = data;
}

int numNodes(Node<int>* head) {
	int i = 1;
	Node<int>* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
		i++;
	}
	return i;
}

void printv(Node<int>* list) {
	Node<int>* temp = list;

	do {
		cout << temp->data << ' ';
		temp = temp->next;
	} while (temp->next != NULL);

	cout << temp->data << endl;
}

void delNode(Node<int>* head, Node<int>* n) { 
	Node<int>* prev = head;

	// Check if node exists in the list
	if (prev->next == NULL)
	{
		cout << "\nThe node is not in the list.";
		return;
	}

	// finds the previous node  
	while (prev->next != NULL && prev->next != n)
		prev = prev->next;

	// Removes the node from the list  
	prev->next = prev->next->next;

	// deletes node 
	free(n);

	// if node is the head
	if (head == n)
	{
		if (head->next == NULL)
		{
			cout << " The list can't be made empty ";
			return;
		}

		// Copy the data of next node to head
		head->data = head->next->data;

		// store address of next node  
		n = head->next;

		// Remove the link of next node  
		head->next = head->next->next;

		// free memory  
		free(n);

		return;
	}

	return;
}

int main()
{
	Node<int>* head = NULL; // creates a pointer to a NODE, then sets that to NULL
	head = new Node<int>(); // these actually set the each pointer to a newly created node
	head->data = 1;

	createNode(head, 5);
	createNode(head, 4);
	createNode(head, 10);
	createNode(head, 47);
	createNode(head, 22);

	cout << numNodes(head) << endl;

	printv(head);

	delNode(head, head->next->next); // breaks for some reason

	printv(head);

	return 0;
}
