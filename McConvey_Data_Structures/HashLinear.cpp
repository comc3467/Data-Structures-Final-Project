#include <iostream>
#include "HashLinear.hpp"
using namespace std;

HashTable::HashTable(){
    for(int i = 0; i < 40009; i++){
        table[i] = 0;
    }
}

bool HashTable::insertItem(int key){
    int index = hashFunction(key);
    bool inserted = false;
    while(inserted == false){
        if(table[index % 40009] == 0){
            table[index % 40009] = key;
            inserted = true;
        }
        else{
            index++;
            numOfcolision++;
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
int HashTable::searchItem(int key){ //returns iteration
    int index = hashFunction(key);
    bool found = false;
    while(found == false){
        if(table[index % 40009] != key){
            index++;
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

