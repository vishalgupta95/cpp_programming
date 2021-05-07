#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <list>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
 
// Function to print level order traversal of a perfect binary tree
void levelOrderTraversal(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    // create an empty queue and enqueue the root node
    list<Node*> queue;
    queue.push_back(root);
 
    // pointer to store the current node
    Node* curr = nullptr;
 
    // loop till queue is empty
    while (queue.size())
    {
        // process each node in the queue and enqueue their
        // non-empty left and right child
        curr = queue.front();
        queue.pop_front();
 
        cout << curr->data << " ";
 
        if (curr->left) {
            queue.push_back(curr->left);
        }
 
        if (curr->right) {
            queue.push_back(curr->right);
        }
    }
}
 
// Recursive function to invert alternate levels of a perfect binary tree
// using preorder traversal
void invertBinaryTree(Node* first, Node* second, bool level)
{
    // return if either child is empty
    if (!first || !second) {
        return;
    }
 
    // swap data only if the level is odd
    if (level) {
        swap(first->data, second->data);
    }
 
    // recur with the left child of `first` and the right child
    // of `second` with an updated level
    invertBinaryTree(first->left, second->right, !level);
 
    // recur with the right child of `first` and left child of
    // `second` with an updated level
    invertBinaryTree(first->right, second->left, !level);
}
 
void invertBinaryTree(Node* root) {
    invertBinaryTree(root->left, root->right, true);
}
 
int main()
{
    /* Construct the following tree
                  1
               /     \
             /         \
           2             3
         /   \         /   \
        4     5       6     7
      /  \    / \    / \    / \
     8    9  10 11 12  13  14 15
 
    */
 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);
 
    invertBinaryTree(root);
    levelOrderTraversal(root);
 
    return 0;
}
