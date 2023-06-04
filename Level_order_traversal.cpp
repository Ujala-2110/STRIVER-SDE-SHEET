/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
***********************************************************/

#include<bits/stdc++.h>
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>v;
    if (root == NULL) return v;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    
    while(!q.empty())
    {
        BinaryTreeNode<int> *curr = q.front();
        q.pop();
        v.push_back(curr->val);
        
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    
    return v;
}








