/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
int func(BinaryTreeNode<int>*root,int x,int &ans)
{     
    if(root == NULL) return ans;
    if(root->data == x){
        return x;
    }
    if(root->data > x){
        ans = root->data;
        return func(root->left,x,ans);
    }
    else{
        return func(root->right,x,ans);
    }
}
int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    int ans = -1;
    int res = func(root,x,ans);
    return res;
}



