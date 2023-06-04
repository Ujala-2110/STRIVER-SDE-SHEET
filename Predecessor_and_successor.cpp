/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
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
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
   pair<int,int>p;
   p.first = -1;
   p.second = -1;
   while(root)
    {
        if(root->data == key){           
            if(root->left) p.first = root->left->data;
            if(root->right) p.second = root->right->data;
            root = root->left;
        }
        else{
            if(root->data < key){
                p.first = root->data;
                root = root->right;
            }
            
            else{
                p.second = root->data;
                root = root->left;
            }
        }
    }
    
    return p;
}
