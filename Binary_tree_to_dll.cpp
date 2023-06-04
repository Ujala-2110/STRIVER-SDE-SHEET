/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>

BinaryTreeNode<int>* func(BinaryTreeNode<int>* root, BinaryTreeNode<int>** prev,
BinaryTreeNode<int>** head)
{
    if(root == NULL) return *head;

    func(root->left,prev,head);

    if(*prev == NULL) *head = root;
    else{
        root->left = *prev;
        (*prev)->right = root;
    }

    *prev = root;
    func(root->right,prev,head);

    return *head;
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
   BinaryTreeNode<int> *prev = NULL, *head = NULL;
   return func(root,&prev,&head);
}








