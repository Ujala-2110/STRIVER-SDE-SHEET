/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int key) {
    // Write your code here.
    if (root == NULL) return false;
    if(root->data == key) return true;
    if (root->data < key) return searchInBST(root->right, key);
    return searchInBST(root->left, key);
}





