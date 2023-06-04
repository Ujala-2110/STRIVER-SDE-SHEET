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
int ans = 0;

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(!root) return ans;
    if(root->val == X) return X;
    if(root->val > X) return floorInBST(root->left,X);
    if(root->val < X){
        ans = root->val;
        return floorInBST(root->right,X);
    }   
    return ans;
}









