//2.Write a program to return the sum of all nodes present in a generic tree using recursion
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    vector<Node*> child;
};
 

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    return temp;
}
 

int sumNodes(Node* root)
{
    
    int sum = 0;
 
    if (root == NULL)
        return 0;
 
   
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        int n = q.size();
 
      
        while (n > 0) {
 
           
            Node* p = q.front();
            q.pop();
            sum += p->key;
 
           
            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
    }
    return sum;
}
 

int main()
{
    
    Node* root = newNode(20);
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(34));
    (root->child).push_back(newNode(50));
    (root->child).push_back(newNode(60));
    (root->child).push_back(newNode(70));
    (root->child[0]->child).push_back(newNode(15));
    (root->child[0]->child).push_back(newNode(20));
    (root->child[1]->child).push_back(newNode(30));
    (root->child[2]->child).push_back(newNode(40));
    (root->child[2]->child).push_back(newNode(100));
    (root->child[2]->child).push_back(newNode(20));
    (root->child[0]->child[1]->child).push_back(newNode(25));
    (root->child[0]->child[1]->child).push_back(newNode(50));
 
    cout << sumNodes(root) << endl;
 
    return 0;
}
