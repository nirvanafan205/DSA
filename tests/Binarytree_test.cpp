#include <gtest/gtest.h>
#include "../BST.cpp"

using namespace std;

// inOrder traversal
TEST(BST_traversals, inOrder)
{
	// creating tree
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// capture output that is pritned in console 
	testing::internal::CaptureStdout(); // sets up capture and redirect output stream
	printInorder(root);
	string output = testing::internal::GetCapturedStdout(); // retrieves captured output and is named

	string expected = "4 2 5 1 3 ";
	EXPECT_EQ(output, expected);
}

TEST(BST_traversals, postOrder)
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	testing::internal::CaptureStdout();
	printPostOrder(root);
	string output = testing::internal::GetCapturedStdout();

	string expected = "4 5 2 3 1 ";
	EXPECT_EQ(output, expected);
}

// preOrder traversal
TEST(BST_traversals, preOrder)
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	testing::internal::CaptureStdout();
	printPreOrder(root);
	string output = testing::internal::GetCapturedStdout();

	string expected = "1 4 2 5 3 ";
	EXPECT_EQ(output, expected);
}

// checks that deallocateTree function is working
TEST(deletion, deleteTree)
{
	Node* root = newNode(1);

	deallocateTree(root);

	EXPECT_TRUE(root !=  nullptr);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
