/*

Given a binary tree, perform vertical traversal of it. In vertical traversal, we print nodes of a binary tree in vertical 
order by assuming that the left and right child of a node makes 45 degree angle with the parent. 
This problem can be easily solved with the help of Hashing and pre order traversal.

The idea is to create an empty map where each key represents the relative horizontal distance of a node from the root node and i
value in the map maintains all nodes present at same horizontal distance. Then we do a of the tree and we update the map. For each 
node, we recur for its left subtree by decreasing horizontal distance by 1 and recur for right subtree by increasing 
horizontal distance by 1.

                                   1
                          2               3
                                   5          6
                                    
                            7         8


For above binary tree, the final values in the map will be

-1 -> [2, 7]
0 -> [1, 5]
1 -> [3, 8]
2 -> [6]

*/

#include<iostream>
#include<map>
#include<queue>
using namespace std;
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node
{
    int data;
    Node* left;
    Node* right;
    /*For initilaizing the Node*/
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void helpVertical(Node* rt,int h,map<int,vector<int> > &mp)
{
       /* PreOrder Traversal */
    if(rt==NULL)
         return;
    mp[h].push_back(rt->data);
    helpVertical(rt->left,h-1,mp);
    helpVertical(rt->right,h+1,mp);
}
void vertical(Node* rt)
{ 
       /*Using Hashing to Store the Data*/
    map<int,vector<int> > mp;
    map<int,vector<int> >::iterator it;
    int h=0;
    helpVertical(rt,h,mp);
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" -> [";
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<", ";
        }
        cout<<"\b\b]"<<endl;
    }
}
/* DRIVER FUNCTION */
int main()
{
    /*Insert the Elements according to the Tree (Picture)*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
       root->right->left->right = new Node(8);
    cout<<"Vertical Order Traversal of the given Tree is "<<endl;
    vertical(root);
    return 0;
}



/*  method 2

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    vector<vector<int>> verticalOrder(TreeNode* root) {

        vector<vector<int> > result;

        if(!root)
            return result;

        map<int,vector<int> > m;

        queue<pair<TreeNode *,int> > q;

        q.push(make_pair(root, 0));

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            if(m.find(top.second) == m.end())
                m.insert(make_pair(top.second, vector<int> ()));

            m[top.second].push_back(top.first->val);

            if(top.first->left)
                q.push(make_pair(top.first->left, top.second-1));

            if(top.first->right)
                q.push(make_pair(top.first->right, top.second+1));

        }

        for(auto vec: m) {
            result.push_back(vector<int> ());
            result.back() = vec.second;
        }

        return result;

    }
}

*/














