#include <iostream>
#include "HashChain.hpp"
using namespace std;

HashTable::HashTable(int bsize){
    tableSize = bsize;
    table = new node*[tableSize];
}
bool HashTable::insertItem(int key){
    if(!table[hashFunction(key)]){
        table[hashFunction(key)] = createNode(key, NULL);
    }
    else{
        numOfcolision++; //increment to keep track
        table[hashFunction(key)] = createNode(key, table[hashFunction(key)]);
    }
    return true;
}

unsigned int HashTable::hashFunction(int key){
    return key % tableSize;
}

void HashTable::printTable(){
    for(int i = 0; i < tableSize; i++){
        if(table[i]){
            node* temp = table[i];
            while(temp != NULL){
                cout << "Index: " << i << " Value: " << temp->key << endl;
                temp = temp->next;
            }
        }
    }
}

int HashTable::getNumOfCollision(){
    return numOfcolision;
}

node* HashTable::searchItem(int key){
    node* temp = table[hashFunction(key)];
    while(temp->key != key){
        temp = temp->next;
        if(temp == NULL){
            break;
        }
    }
    return temp;
}

