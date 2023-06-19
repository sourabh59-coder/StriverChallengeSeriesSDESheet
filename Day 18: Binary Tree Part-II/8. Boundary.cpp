#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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

bool isLeaf(TreeNode<int>* root)
{
    return (root!=NULL && root->right==NULL && root->left==NULL);
}

void AddLeft(TreeNode<int>* root,vector<int> &ans)
{
    root = root->left;

    while(root!=NULL)
    {
        if(!isLeaf(root))   ans.push_back(root->data);
        if(root->left)  root = root->left;
        else    root = root->right;
    }
}

void AddLeaf(TreeNode<int>* root,vector<int> &ans)
{
    if(root==NULL)  return;
    if(isLeaf(root))
    {
        ans.push_back(root->data);
    }    
    AddLeaf(root->left, ans);

    AddLeaf(root->right, ans);
}

void AddRight(TreeNode<int>* root,vector<int> &ans)
{
    vector<int> temp;

    root = root->right;

    while(root!=NULL)
    {
        if(!isLeaf(root))   temp.push_back(root->data);
        if(root->right) root = root->right;
        else    root = root->left;
    }

    for(int i=temp.size()-1;i>=0;i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL)  return ans;
    
    if(!isLeaf(root))   ans.push_back(root->data);
    
    AddLeft(root,ans);

    AddLeaf(root,ans);

    AddRight(root,ans);

    return ans;
}
