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
int ans;
void func(TreeNode<int> *root, int &k)
{
    if(root == NULL) return;

    func(root->left,k);

    k--;
    if(k == 0){
        ans = root->data;
        return;
    }
    func(root->right,k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    func(root,k);
    return ans;
}


