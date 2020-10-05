#ifndef HASH_HPP
#define HASH_HPP

#include <string>
 ///group description:
 //Josh Quarderer completed the binary search tree and linked list.
 //Conlan McConvey completed the variations of the hash table
 //Both group members collaborated on the data collections and displaying of data -- worked on Zoom video syncronously

using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision =0;
    node* createNode(int key, node* next);
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    node* searchItem(int key);
};

#endif
