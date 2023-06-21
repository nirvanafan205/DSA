#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node();

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
void printPreOrder(struct Node* node)
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

void deallocateTree(Node* root)
{
	if(root == nullptr)
	{
		return;
	}

	deallocateTree(root->left);
	deallocateTree(root->right);

	delete root;
}


int main()
{
	// create binary tree
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// perform inorder traversal
	cout << "Inorder Traversal: ";
	printInorder(root);
	cout << endl; 

	// perform postorder traversal
	cout << "Postorder Traversal: ";
	printPostOrder(root);
	cout << endl;


	// perform postorder traversal
	cout << "Preorder Traversal: ";
	printPreOrder(root);
	cout << endl;

	// deallocate memory
	deallocateTree(root);
}
