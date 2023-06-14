#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    // initializing stacks n queues
    stack<int> myStack;
    queue<int> myQueue;

    //pushing elements into stack n queue
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // printing

    while(!myQueue.empty())
    {
        // prints top of stack n queue with top() and front() functions
        cout << "Stack: " <<  myStack.top() << " ";
        cout << "Queue: " << myQueue.front() << " ";

        //  pops elements on top 
        myStack.pop();
        myQueue.pop();
    }
}