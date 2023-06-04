#include<bits/stdc++.h>

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void Inorder(TreeNode *root,vector<int>&v)
{
    if(root == NULL) return;
    Inorder(root->left,v);
    Inorder(root->right,v);
    v.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>v;
    Inorder(root,v);
    return v;
}


