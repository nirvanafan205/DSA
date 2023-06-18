#include <iostream>

using namespace std;

// creating Node struct
// contains data,
// pointer to the previous node 
// contains a pointer to the next node
struct Node
{
    int data;
    Node* next;
    Node* prev;
}

// insert function 
//creates a new node and inserts at the end of the list
void insert(Node** head, int data) // this is taking a double pointer to the head node and the data to be inserted
{
    // creates a new node using dynamic memory allocation
    Node* newNode = new Node;

    // assigns the data parameter to the data member of the new node
    newNode->data = data;

    // sets prev and next pointers of the new node to nullptr
    // as it'll be inserted at the end of the list
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // node checking 

    // checks if head pointer is nullptr
    if(*head == nullptr)
    {
        // if list is empty, it updates the head to point to the new node
        //making it the first node in the list
        *head = newNode;
    }

    // chekcs if it's not empty
    else
    {
        // initializes a temp pointer to the head node
        Node* temp = *head;

        // traverses the list using temp until it reaches the last node
        while(temp->next != nullptr)
        {
            // updates next pointer of the last node to point to the new node
            // it's inserted at the end of the list
            temp = temp->next;
        }

        // updates nextr and prev pointer of the new node to the last node
        temp->next = newNode;
        newNode->prev = temp;
    }
    // function creates a new node with the provided data and inserts it at the end of the doubly linked list.
    // It handles both the case when the list is empty and when it already contains elements.  
}

// regular traversal
// takes a pointer to the head node as a parameter
void display(Node* head)
{
    // initializes temporary pointer to the head node
    Node* temp = head;

    // enters a loop, prints data of current node
    // moves temp pointer to the next node
    // loop continues until all nodes in the list have been visted
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    /*
         function traverses doubly linked list starting from the head node
         prints data of each node in the forward order
         uses temp pointer to iterate through the list
    */
}

// reverse traversal
// takes a pointer to the head node as a parameter
void reverse(Node* head)
{
    // initializes a temp pointer to the head node
    Node* temp = head;

    // enters a loop that continues until the next pointer of temp becomes nullptr
    // this will indicate that it's at the last node in the list
    while(temp->next != nullptr)
    {
        // updates temp pointer to the next node
        temp = temp->next;
    } // temp points to the last node of the list


    // enters another loop that continues until temp pointer becomes nullptr
    // this will show that it's at the beginning of the list
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

// delete node function @ specific key
// takes a double pointer to the head node and the data value of the node to be deleted
void deleteNode(Node** head, int data)
{
    // checks if list is empty
    if(*head == nullptr)
    {
        return;
    }

    // initializes a temporary pointer to the head node
    Node* current = *head;

    // finds node to be deleted
    // continues until either the end of the list is reached
    // or the data value of the current node mates the data value provided
    while(current != nullptr && current->data != data)
    {
        current = current->next;
    } // if loop exists because current becomes nullptr, value wsas not found in the list

    if(current == nullptr)
    {
        return;
    }

    // prev pointer stuff
    // if node to be deleted is not the first node
    if(current->prev != nullptr)
    {
        // updates prev node's next poniter to skip current node
        // removes the currend node from the list
        current->prev->next = current->next;
    }

    // if the node to be deleted is the first node
    else 
    {
        // updating head pointer
        // if deleting the node first
        // ensures list is still valid and doesn't have dangling reference to the deleted node
        *head = current->next;
    }

    // if node to be deleted is next node
    if(current->next != nullptr)
    {
        // updates next node's prev poniter
        current->next->prev = current->prev;
    }

    // used to deallocate the memory occupied by the current node
    // deletes it from the list
    delete current;
}

int main()
{
    Node* head = nullptr;

    insert(&head, 2);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 89);

    cout << "Forward display: ";
    display(head);

    cout << "Reverse display: ";
    reverse(head);

    cout << "After deletion: "; 

    deleteNode(&head, 9);
    display(head);
}