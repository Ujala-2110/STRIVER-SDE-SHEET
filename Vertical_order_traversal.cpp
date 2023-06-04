/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>ans;
    if(!root) return ans;
    multimap<int,int>mp;
    queue<pair<TreeNode<int> *,int>>q;
    q.push({root,0});
    
    while(!q.empty())
    {
        TreeNode<int> *t = q.front().first;
        int h = q.front().second;
        q.pop();
        
        mp.insert({h,t->data});
        if(t->left) q.push({t->left,h-1});
        if(t->right) q.push({t->right,h+1});
    }
    
    for(auto it : mp) ans.push_back(it.second);
    return ans;
}
