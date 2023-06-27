#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

// insert function to ad new node at the beginning of the linked list
void insertNode(Node **head, int data)
{
	// creates a new node dynamically
	// assigns the memory address of the newly created node to the newNode pointer
	Node *newNode = new Node;

	// the value of the new node is set to
	// the value passed as a parameter to the function
	newNode->data = data;

	// assings next poniter to the new node to the current head node
	// links new node to the existing linkedlist
	newNode->next = *head;

	// updates the head pointer to the newly inserted node
	// makes the new node of the new head of the linkedlist
	*head = newNode;
}

// function to delete a node with a given key from the linked list

void deleteNode(Node **head, int key)
{
	Node *prev = nullptr;
	Node *current = *head;

	// If the head node itself holds the key to be deleted
	if (current != nullptr && current->data == key)
	{
		*head = current->next;
		delete current;
		return;
	}

	// search for the key to be deleted, keeping track of the previous node

	while (current != nullptr && current->data != key)
	{
		prev = current;
		current = current->next;
	}

	// if the key was not found in the linked list
	if (current == nullptr)
	{
		return;
	}

	// unlinks the node from thew linked list
	prev->next = current->next;
	delete current;
}

// function to insert node at the end of the linked list
void insertAtEnd(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	// if the list is empty, make the new node the head
	if(*head == nullptr)
	{
		*head = newNode;
		return;
	}

	Node* current = *head;

	// traverse to the last node of the list
	while(current->next != nullptr)
	{
		current = current->next;
	}

	// insert the new node after the last node
	current->next = newNode;
}

// inserting node data after a specific node in the list
void insertAfter(Node* prevNode, int data)
{
	if(prevNode == nullptr)
	{
		// nothing happens if node isn't found
		
		cout << "Previous node can't be nullptr." << endl;

		return;
	}

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

// function to print the linked list
void printList(Node *head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}

int main()
{
	// Create an empty linked list
	Node *head = nullptr;

	// Insert nodes ast the beginning
	insertNode(&head, 5);
	insertNode(&head, 4);
	insertNode(&head, 3);
	insertNode(&head, 2);
	insertNode(&head, 1);

	cout << "Linked list: ";

	printList(head);

	// delete node
	deleteNode(&head, 2);

	cout << "Linked list after deletion: ";
	printList(head);

	cout << "Linked List after inserting at the end: ";
	insertAtEnd(&head, 99);
	insertAtEnd(&head, 23);
	insertAtEnd(&head, 33);
	printList(head);

	cout << "Inserting nodes again at the front of the Linked List: ";
	insertNode(&head, 5);
	insertNode(&head, 21);
	insertNode(&head, 234);
	printList(head);

	// inserting a specific node value after a given number in the list
	// in this example I will use 2
	Node* node2 = head->next;

	insertAfter(node2, 0);
	cout << "New node after 2 is placed: ";
	printList(head);
}
