#include <iostream>
#include <math.h>
#include "HashQuad.hpp"
using namespace std;

HashTable::HashTable(){
    for(int i = 0; i < 40009; i++){
        table[i] = 0;
    }
}

bool HashTable::insertItem(int key){
    int index = hashFunction(key);
    bool inserted = false;
    int i = 1;
    while(inserted == false){
        if(table[index % 40009] == 0){
            table[index % 40009] = key;
            inserted = true;
        }
        else{
            index += pow(i, 2.0);
            numOfcolision++;
            i++;
        }
    }
    return inserted;
}

unsigned int HashTable::hashFunction(int key){
    return key % 40009;
}

void HashTable::printTable(){
    for(int i = 0; i < 40009; i++){
        if(table[i] != 0){
            cout << "Index: " << i << " Value: " << table[i] << endl;
        }
    }
}
int HashTable::searchItem(int key){
    int index = hashFunction(key);
    bool found = false;
    int i = 1;
    while(found == false){
        if(table[index % 40009] != key){
            index += pow(i, 2.0);
            i++;
        }
        else{
            found = true;
        }
    }
    return (index % 40009);
}
int HashTable::getNumOfCollision(){
    return numOfcolision;
}

