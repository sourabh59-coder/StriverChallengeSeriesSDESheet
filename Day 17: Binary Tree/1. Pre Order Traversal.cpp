void PreOrderTraversal(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)  return;
        
        ans.push_back(root->val);
        
        PreOrderTraversal(root->left,ans);
        
        PreOrderTraversal(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        PreOrderTraversal(root,ans);
        
        return ans;
    }
