#include<bits/stdc++.h>

//  * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    
    int f(TreeNode *root, int & ans)
    {
        if(root == NULL) return 0;

        int lh = f(root->left,ans);
        int rh = f(root->right,ans);

        ans = max(ans , (lh+rh));
        return max(lh,rh)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;
        int ans = INT_MIN;
        f(root,ans);
        return ans;
    }
};