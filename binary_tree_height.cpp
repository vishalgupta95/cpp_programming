
/*
1>Height of a node is the no of edges we travel between the root node and node , 
2>A tree with only root node has height 0 
3>A tree with only  2 node has height 1 
4>tree with zero nodes would be considered as empty. An empty tree has height of -1.
5>left skewed binary tree shown  with 5 nodes has height 5-1 = 4 
6> itterative approach

*/
#include <iostream>
#include <queue>

using namespace std;
#include <iostream>
#include <list>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Iterative function to calculate the height of a given binary tree
// by doing level order traversal on the tree
int height(Node* root)
{
    // empty tree has a height of 0
    if (root == nullptr) {
        return 0;
    }
 
    // create an empty queue and enqueue the root node
    list<Node*> queue;
    queue.push_back(root);
 
    Node* front = nullptr;
    int height = 0;
 
    // loop till queue is empty
    while (!queue.empty())
    {
        // calculate the total number of nodes at the current level
        int size = queue.size();
 
        // process each node of the current level and enqueue their
        // non-empty left and right child
        while (size--)
        {
            front = queue.front();
            queue.pop_front();
 
            if (front->left) {
                queue.push_back(front->left);
            }
 
            if (front->right) {
                queue.push_back(front->right);
            }
        }
 
        // increment height by 1 for each level
        height++;
    }
 
    return height;
}
 
int main()
{
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    cout << "The height of the binary tree is " << height(root);
 
    return 0;
}

