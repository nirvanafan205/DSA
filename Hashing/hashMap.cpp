#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    // create hash table
    unordered_map<string, int> myHash;

    // Insert key-value pairs into the hash table

    myHash["Alice"] = 25;
    myHash["Bob"] = 30;
    myHash["Charlie"] = 35;

    // Access and print values using keys
    cout << "Age of Alice: " << myHash["Alice"] << endl;
    cout << "Age of Bob: " << myHash["Bob"] << endl;

    // check if a key exists in the hash table
    string name = "Charlie";

    if (myHash.count(name) > 0)
    {
        cout << name << " is in the hash table" << endl;
    }

    else
    {
        cout << name << " is not in the hash table" << endl;
    }

    // Remove a key-value pair from the hash table
    string remove = "Bob";
    myHash.erase(remove);

    // checks if the key still exists
    if (myHash.count(remove) > 0)
    {
        cout << remove << " is in the hash table" << endl;
    }

    else
    {
        cout << remove << " is not in the hash table" << endl;
    }
}