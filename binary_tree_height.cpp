//For example, left skewed binary tree shown in Figure 1(a) with 5 nodes has height 5-1 = 4 and binary tree shown in Figure 1(b) 
//with 5 nodes has height floor(log25) = 2.

#include <iostream>
using namespace std;

struct Node{
  Node* left;
  Node* right;
};

Node* createTree(){
  Node* root = new Node;
  
  // Creating 2nd level:
  Node* one = new Node;
  Node* two = new Node;
  root->left = one;
  root->right = two;

  // Creating 3rd level:
  Node* three = new Node;
  Node* four = new Node;
  Node* five = new Node;
  one->left = three;
  two->left = four;
  two->right = five;
  
  return root;
}

int findMax(int a, int b){
  if(a >= b)
    return a;
  else
    return b;
}

int findHeight(Node* root){
  // Base case:
  if(root == NULL)
    return 0;

  return findMax(findHeight(root->left), findHeight(root->right)) + 1;
}

int main() {
  
  Node* root = createTree();
  cout << "Height of tree: " << findHeight(root);
  return 0;
}
