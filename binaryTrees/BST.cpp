#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
}

Node* newNode(int data)
{
	Node* temp = newNode;

	temp->data = data;

	temp->left = temp->right = NULL;

	return temp;
}

// inOrder traversal
void printInorder(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}

	//recur on left child 
	printInorder(node->left);

	//print data
	cout << node->data << " ";

	//recur on right child 
	printInorder(node->right);
}

//preOrder traversal
void print PreOrder(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}
	
	//print data
	cout << node->data << " ";

	//recur on left child 
	printInorder(node->left);

	//recur on right child 
	printInorder(node->right);
}

void printPostOrder(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}

	printPostOrder(node->left);

	printPostOrder(node->right);

	cout << node->data << " ";
}