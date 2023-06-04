/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* build(vector<int>&A, int &i , int bound)
{
    if(i == A.size() || A[i] > bound) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(A[i++]);
    root->left = build(A,i,root->data);
    root->right = build(A,i,bound);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here
    int i = 0;
    return build(preOrder,i,INT_MAX);
}









