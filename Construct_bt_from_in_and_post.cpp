/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int> *BuildTree(vector<int>&postorder,int postst, int posted , vector<int>&inorder, int         inst, int ined , map<int,int>&mp)
        {
            if(postst > posted || inst > ined) return NULL;

            TreeNode<int>* root = new TreeNode<int>(postorder[posted]);

            int inroot = mp[root->data];
            int numsleft = inroot-inst;

            root->left = BuildTree(postorder, postst, postst+numsleft-1 ,inorder, inst, inroot - 1,mp);
            root->right = BuildTree(postorder, postst+numsleft, posted-1 ,inorder, inroot+1, ined ,mp);

            return root;
        }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    map<int,int>mp;

    for(int i=0;i<inOrder.size();i++) mp[inOrder[i]] = i;

    TreeNode<int> *root = BuildTree(postOrder,0,postOrder.size()-1,inOrder,0,inOrder.size()-1,mp);

    return root;
}
