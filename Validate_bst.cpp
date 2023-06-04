/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool func(TreeNode *root,long mini)
    {
        if(root == NULL) return true;

        if(root->val <= mini) return false;

        return (func(root->left,mini) && func(root->right,root->val));
    }
    
    bool isValidBST(TreeNode* root) {
        
        return func(root,-1e15);
    }

};

































