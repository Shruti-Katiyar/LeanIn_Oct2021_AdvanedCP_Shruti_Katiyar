//1.Given a generic tree, write a program to print the tree level wise
#include <bits/stdc++.h> 
using namespace std; 
   
struct Node 
{ 
    int key; 
    vector<Node *>child; 
}; 
   
 
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    return temp; 
} 
  
 
void LevelOrderTraversal(Node * root) 
{ 
    if (root==NULL) 
        return; 
   
   
   
    queue<Node *> q;  
    q.push(root); 
    while (!q.empty()) 
    { 
        int n = q.size(); 
  
        
        while (n > 0) 
        { 
            
            Node * p = q.front(); 
            q.pop(); 
            cout << p->key << " "; 
   
            
            for (int i=0; i<p->child.size(); i++) 
                q.push(p->child[i]); 
            n--; 
        } 
   
        cout << endl; 
    } 
} 
   

int main() 
{ 
    
    Node *root = newNode(10); 
    (root->child).push_back(newNode(2)); 
    (root->child).push_back(newNode(34)); 
    (root->child).push_back(newNode(56)); 
    (root->child).push_back(newNode(100)); 
    (root->child[0]->child).push_back(newNode(77)); 
    (root->child[0]->child).push_back(newNode(88)); 
    (root->child[2]->child).push_back(newNode(1)); 
    (root->child[3]->child).push_back(newNode(7)); 
    (root->child[3]->child).push_back(newNode(8)); 
    (root->child[3]->child).push_back(newNode(9)); 
   
    
    LevelOrderTraversal(root); 
    
    return 0; 
}  
