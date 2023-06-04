/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };
*/

#include<bits/stdc++.h>
long long dfs(TreeNode<int> *root, long long &ans) {
    if(!root) return 0;
    long long l = max(0ll,dfs(root->left, ans));
    long long r = max(0ll,dfs(root->right, ans));
    ans = max(ans, root->val+l+r);
    return root->val + max(l, r);
} 

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root || !root->left || !root->right) return -1;
    long long ans = INT_MIN;
    dfs(root, ans);
    return ans;
}