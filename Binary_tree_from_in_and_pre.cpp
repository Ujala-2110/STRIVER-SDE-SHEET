/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
TreeNode<int> * BuildTree(vector<int>&preorder,int prest,int preed,vector<int>&inorder, int inst, int ined, map<int,int>&mp)
{
    if(prest>preed || inst>ined) return NULL;

    TreeNode<int>  *root = new TreeNode<int>(preorder[prest]);

    int inRoot = mp[root->data];
    int numsleft = inRoot - inst;

    root->left = BuildTree(preorder,prest+1,prest+1+numsleft,inorder,inst,inRoot-1,mp);
    root->right = BuildTree(preorder,prest+1+numsleft,preed,inorder,inRoot+1,ined,mp);

    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    map<int,int>mp;

    for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;

    TreeNode<int>  *root = BuildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    return root;
}







