void PreOrder(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root==NULL)  return;

    ans.push_back(root->data);

    PreOrder(root->left,ans);

    PreOrder(root->right,ans);
}

void InOrder(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root==NULL)  return;

    InOrder(root->left,ans);

    ans.push_back(root->data);

    InOrder(root->right,ans);
}

void PostOrder(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root==NULL)  return;

    PostOrder(root->left,ans);

    PostOrder(root->right,ans);

    ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> final;

    vector<int> v;

    InOrder(root,v);

    final.push_back(v);

    v.clear();

    PreOrder(root,v);

    final.push_back(v);

    v.clear();

    PostOrder(root,v);

    final.push_back(v);

    v.clear();

    return final;
}
