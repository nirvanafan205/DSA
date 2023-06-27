#include <gtest/gtest.h>
#include "../LinkedList.cpp"

using namespace std;

// insertion
TEST(LinkedListTest, insertFunction)
{
	Node* head = nullptr;

	// insert nodes 
	insertNode(&head, 3);
	insertNode(&head, 2);
	insertNode(&head, 1);

	// checking value of individual nodes
	ASSERT_EQ(head->data, 1); // checks first node
	ASSERT_EQ(head->next->data, 2); // checks second node
	ASSERT_EQ(head->next->next->data, 3); // checks third node
	ASSERT_EQ(head->next->next->next, nullptr); // checks fourth node
}

TEST(LinkedListTest, deleteFunction)
{
	Node* head = nullptr;

	// insert nodes 
	insertNode(&head, 3);
	insertNode(&head, 2);
	insertNode(&head, 1);

	// deleting node
	deleteNode(&head, 2);

	ASSERT_EQ(head->next->data, 3); // checks second node
	ASSERT_EQ(head->next->next, nullptr); // checks third node
}

TEST(LinkedListTest, insertEnd)
{
	// Create an empty linked list
	Node *head = nullptr;

	// Insert nodes ast the beginning
	insertNode(&head, 3);
	insertNode(&head, 2);
	insertNode(&head, 1);

	// delete node
	deleteNode(&head, 2);

	insertAtEnd(&head, 99);
	insertAtEnd(&head, 33);

	ASSERT_EQ(head->next->next->data, 99);
}

TEST(LinkedListTest, insertAfterNode)
{
	// Create an empty linked list
	Node *head = nullptr;

	// Insert nodes ast the beginning
	insertNode(&head, 3);
	insertNode(&head, 2);
	insertNode(&head, 1);

	Node* node = head->next;

	insertAfter(node, 0);

	ASSERT_EQ(head->next->next->data, 0);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
