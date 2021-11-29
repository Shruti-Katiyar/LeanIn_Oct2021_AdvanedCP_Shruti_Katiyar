//2.For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.
#include <iostream>
#include <queue>
using namespace std;
 

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
 

void printLevelOrder(node *root)
{
    // Base Case
    if (root == NULL) return;
 
  
    queue<node *> q;
 
  
    q.push(root);
 
    while (q.empty() == false)
    {
    
        int nodeCount = q.size();
 
        while (nodeCount > 0)
        {
            node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}
 

node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 

int main()
{
  
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    printLevelOrder(root);
    return 0;
}
