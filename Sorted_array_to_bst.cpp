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
TreeNode<int>* func(vector<int>&nums , int st , int ed)
{
    if(st > ed) return NULL;

    int mid = (st+ed)/2;
    TreeNode<int>* root = new TreeNode<int>(nums[mid]);

    root->left = func(nums,st,mid-1);
    root->right = func(nums,mid+1,ed);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here
    TreeNode<int> *root = func(arr,0,n-1);
    return root;
}