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
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>v;
    queue<BinaryTreeNode<int> *>q;
    if(root == NULL) return v;
    q.push(root);
    int level = 0;
    while(!q.empty())
    {
        int n = q.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();

            if(level % 2 == 0)
            {
                v.push_back(curr->data);
            }
            else{
                s.push(curr->data);
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        level++;
    }
    return v;
}


