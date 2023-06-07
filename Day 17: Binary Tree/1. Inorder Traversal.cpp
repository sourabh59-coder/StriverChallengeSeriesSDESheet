void InorderTraversal(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)  return;
        
        InorderTraversal(root->left,ans);
        
        ans.push_back(root->val);
        
        InorderTraversal(root->right,ans);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        InorderTraversal(root,ans);
        
        return ans;
    }
