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

	do {
		cout << list->data << ' ';
		list = list->next;
	} while (list->next != NULL);

	cout << list->data << endl;
}

int main()
{
	Node<int>* head = NULL; // creates a pointer to a NODE, then sets that to NULL
	head = new Node<int>(); // these actually set the each pointer to a newly created node
	head->data = 1;

	createNode(head, 5);
	createNode(head, 4);
	createNode(head, 22);

	cout << numNodes(head) << endl;
	printv(head);

	return 0;
}
