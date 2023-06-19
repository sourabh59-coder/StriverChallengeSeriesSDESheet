#include <bits/stdc++.h> 
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
void fun(BinaryTreeNode<int> *root,int x,int &ans)
{
    if(root==NULL)  return;

    if(root->data==x)
    {
        ans = x;
        return;
    }

    if(root->data < x)
    {
        fun(root->right,x,ans);
    }

    if(root->data > x)
    {
        ans = root->data;
        fun(root->left,x,ans); 
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = -1;
    fun(node,x,ans);
    return ans;
}
