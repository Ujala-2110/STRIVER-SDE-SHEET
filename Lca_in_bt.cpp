/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* lowestCommonA(TreeNode<int> * root,int p,int q) {

    if(root == NULL) return root;

    if((root->data) == p || (root->data) == q) return root;

    TreeNode<int> *left = lowestCommonA(root->left,p,q);
    TreeNode<int> *right = lowestCommonA(root->right,p,q);

    if(left && right) return root;

    else if(left && !right) return left;
    else return right;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    TreeNode<int> *node =  lowestCommonA(root,x,y);
    return node != NULL ?  node->data : 0;
}