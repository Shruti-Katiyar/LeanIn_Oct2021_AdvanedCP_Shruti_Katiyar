//4.Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left, *right,
       *root;
 
  Node(int data)
  {
    this -> data = data;
    left = NULL;
    right = NULL;
    root = NULL;
  }
};
 

Node* AddNode(Node *root,
              int data)
{
  
  if (root == NULL)
  {
    root = new Node(data);
    return root;
  }
 

  if (root -> data < data)
    root -> right = AddNode(root -> right,
                            data);
 
  else if (root -> data > data)
    root -> left = AddNode(root -> left,
                           data);
 
  return root;
}
 
void TargetPair(Node *node,
                int tar)
{

  vector<Node*> LeftList;
 

  vector<Node*> RightList;

  Node *curr_left = node;
  Node *curr_right = node;
 
  while (curr_left != NULL ||
         curr_right != NULL ||
         LeftList.size() > 0 &&
         RightList.size() > 0)
  {

    while (curr_left != NULL)
    {
      LeftList.push_back(curr_left);
      curr_left = curr_left -> left;
    }
 
   
    while (curr_right != NULL)
    {
      RightList.push_back(curr_right);
      curr_right = curr_right -> right;
    }
 
  
    Node *LeftNode =
          LeftList[LeftList.size() - 1];
 

    Node *RightNode =
          RightList[RightList.size() - 1];
 
    int leftVal = LeftNode -> data;
    int rightVal = RightNode -> data;
 
    if (leftVal >= rightVal)
      break;
 
  
    if (leftVal + rightVal < tar)
    {
      LeftList.pop_back();
      curr_left = LeftNode -> right;
    }
 
   
    else if (leftVal + rightVal > tar)
    {
      RightList.pop_back();
      curr_right = RightNode -> left;
    }
 
    else
    {
      cout << LeftNode -> data << " " <<
              RightNode -> data << endl;
 
      RightList.pop_back();
      LeftList.pop_back();
      curr_left = LeftNode -> right;
      curr_right = RightNode -> left;
    }
  }
}
 
// Driver code
int main()
{
  Node *root = NULL;
  root  = AddNode(root, 2);
  root = AddNode(root, 6);
  root = AddNode(root, 5);
  root = AddNode(root, 3);
  root = AddNode(root, 4);
  root = AddNode(root, 1);
  root = AddNode(root, 7);
  int sum = 8;
  TargetPair(root, sum);
}
