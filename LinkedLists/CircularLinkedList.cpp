#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
}

// insert a new node @ the beginning of the circular linked list
void insert(Node** head)
{
    Node* newNode = newNode;
    newNode->data = data;

    if(*head == nullptr)
    {
        // if list is empty
        // make new node 
        // set its next pointer to itself

        *head = newNode;

        newNode->next = newNode;
    }

    else
    {
        // find last node in list
        Node* last = (*head)->next;

        while(last->next != *head)
        {
            last = last->next;
        }

        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
} // end of insert function

// function to delete node w/ a given key from a circular linked list
void delete(Node** head, int key)
{
    // checks if list is empty
    if(*head == nullptr)
    {
        return;
    }

    Node* curr = *head;
    Node* prev = nullptr;

    // find node w/ key to be deleted
    while(curr->data != key)
    {
        // break out of loop if key not found
        if(curr->next == *head)
        {
            break;
        }

        prev = curr;
        cur == curr->next;
    }

    // if node w/ key is found
    if(curr == *head)
    {
        // if its the only node in the list
        // set head to null ptr
        if(curr == *head)
        {
            *head = nullptr;
        }

        else 
        {
            // removes head node and updates
            // next poniter to the last node
            Node* last = *head;

            while(last->next != *head)
            {
                last = last->next;
            }

            *head = curr->next;
            last->next = *head;

            delete curr;
        }
    }

    else if(curr->next == *head)
    {
        // if last node needs to be deleted

        prev->next = *head;

        delete curr;
    }

    else 
    {
        // if node in between needs to be deleted

        prev->next = curr->next;

        delete curr;
    }
} // end of delete function

// function to traverse and display circular linked list
void display(Node* head)
{
    // checks if lists empty
    if(head == nullptr)
    {
        cout << "List is empty: " << endl;

        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
} // end of display function

int main()
{
    Node* head = nullptr;

    // insert nodes into Circular Linked List

    insert(&head, 2);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 89);

    cout << "Original Circular Linked List: ";
    display(head);
    delete(&head, 9);

    cout << "Updated list: ";

    display(head);
}