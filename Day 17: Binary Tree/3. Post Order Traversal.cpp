void PostOrderTraversal(TreeNode* root, vector<int> &ans)
    {
        if(root==NULL)  return;
        
        PostOrderTraversal(root->left,ans);
        
        PostOrderTraversal(root->right,ans);
        
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        PostOrderTraversal(root,ans);
        
        return ans;
    }
