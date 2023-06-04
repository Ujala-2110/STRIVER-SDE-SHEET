/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void in(TreeNode<int> *root , int &cnt)
{
    if(root == NULL) return;

    in(root->left,cnt);
    cnt++;
    in(root->right,cnt);
}

int ans = -1;
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

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int cnt = 0;
    in(root,cnt);

    k = cnt-k + 1;
    if(k <= 0) return -1;
    func(root,k);
    return ans;
}
