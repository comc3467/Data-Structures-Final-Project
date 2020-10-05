//Coded by Josh Quarderer
#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* next;
};

class LL
{
    private:
        Node* head = NULL;
    public:
        LL() {head = NULL;}
        void insert(int n);
        void search(int v);
        void display();
};

void LL::insert(int n)
{
    Node* add = new Node();
    add->key = n;
    add->next = nullptr;

    if(head == NULL) head = add;
    else
    {
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = add;
    }
    
}

void LL::search(int v)
{
    if (head->key == v) {return;}
    else
    {
        Node* temp = head->next;
        int counter = 1;
        while (temp != NULL)
        {
            if (temp->key == v) {return;}
            temp = temp->next;
            counter++;
        }
        //cout << "Value not found." << endl;
    }
}

void LL::display()
{
    if (head == NULL)
    {
        cout << "No data stored." << endl;
    }
    else
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
}