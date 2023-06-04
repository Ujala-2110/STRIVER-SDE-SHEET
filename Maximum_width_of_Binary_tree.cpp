/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;
    queue<TreeNode<int> *>q;
    q.push(root);
    int maxi = INT_MIN;
    
    while(!q.empty())
    {
        int sz = q.size();
        maxi = max(maxi,sz);
        
        for(int i=0;i<sz;i++)
        {
            TreeNode<int> *curr = q.front();
            q.pop();
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    
    return maxi;
}








