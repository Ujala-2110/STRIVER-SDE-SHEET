/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool func(BinaryTreeNode<int>* n1, BinaryTreeNode<int>* n2)
{
    if(n1 == NULL && n2 == NULL) return true;
    
    if(n1 == NULL || n2 == NULL) return false;
    
    if(n1->data != n2->data) return false;
    
    return func(n1->left,n2->right) && func(n1->right,n2->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.  
    if(root == NULL) return true;
    return func(root->left , root->right);
}