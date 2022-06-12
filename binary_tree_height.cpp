//For example, left skewed binary tree shown in Figure 1(a) with 5 nodes has height 5-1 = 4 and binary tree shown in Figure 1(b) 
//with 5 nodes has height floor(log25) = 2.
//Height of a tree is the length of the path from root of that tree to its farthest node (i.e. leaf node farthest from the root).
//A tree with only root node has height 0 and a tree with zero nodes would be considered as empty. An empty tree has height of -1.
// in some books empty tree has height of 0. see here
// The height of a binary tree is found using the recursive Depth-First Search (DFS) algorithm, as shown below:
//
// Base case: If there is no node, return 0.
//
// Else: If there are 1 or 2 children, return the maximum of the height of the left and right sub-trees, plus 1 to account for 
// the current node. The height of a sub-tree is found by recursively calling the function, and passing the child node as the parameter.


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
