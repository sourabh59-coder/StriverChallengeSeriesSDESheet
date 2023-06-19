#include <bits/stdc++.h> 
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

void fun(TreeNode<int> * root,int x, int &ans)
{
    if(root==NULL)  return;

    if(root->val < x)
    {
        ans = root->val;
        fun(root->right,x,ans);
    }

    else if(root->val == x)
    {
        ans = x;
        return;
    }

    else if(root->val > x)
    {
        fun(root->left,x,ans);
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = -1;
    fun(root,X,ans);
    return ans;
}
