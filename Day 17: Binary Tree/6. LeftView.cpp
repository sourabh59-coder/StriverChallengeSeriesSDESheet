void Fun(Node* root,vector<int> &ans,int level)
{
    if(root==NULL)  return;
    
    if(ans.size()==level)   ans.push_back(root->data);
    
    Fun(root->left,ans,level+1);
    
    Fun(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    Fun(root,ans,0);
    return ans;
   // Your code here
}
