#ifndef HASHLIN_HPP
#define HASHLIN_HPP

#include <string>


using namespace std;


class HashTable
{
    int table[40009];
    int numOfcolision =0;
public:
    HashTable();
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    int searchItem(int key);
};

#endif