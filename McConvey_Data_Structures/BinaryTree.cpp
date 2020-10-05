//Coded by Josh Quarderer
#include <iostream>

using namespace std;

struct BNode
{
    int key;
    BNode* left;
    BNode* right;
};

class BST
{
    public:
        BNode* root = NULL;
        int count;
    
        void insert(int val);
        void search(int val);
        void display();
};

void BST::insert(int val)
{
    BNode* add = new BNode; add->key = val;
    add->right = NULL; add->left = NULL;

    if (root == NULL) {root = add; return;}

    else
    {
        BNode* parent = NULL, *temp = root;
        while(temp != NULL)
        {
            parent = temp;
            if (add->key < temp->key)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (parent->key < add->key)
        {
            parent->right = add;
        }
        else
        {
            parent->left = add;
        }
        
    }
    
}

void searchHelper(BNode* currNode, int val)
{
    if (currNode == NULL) {return;}

    int num = currNode->key;
    if (num == val)
    {
        return;
    }
    else if (num < val)
    {
        searchHelper(currNode->right, val);
    }
    else if (num > val)
    {
        searchHelper(currNode->left, val);
    }
    
    
}

void BST::search(int val)
{
    searchHelper(root, val);
}

void printHelper(BNode* curr, int space, int count)
{
    if (curr == nullptr) return;

    space += count;

    printHelper(curr->right, space+count, count);
    cout << "\n";
    for (int i = count; i < space; i++) cout << " ";
    cout << curr->key;
    cout << "\n";
    printHelper(curr->left, space+count, count);
}

void BST::display()
{
    printHelper(root, 0, 10);
}