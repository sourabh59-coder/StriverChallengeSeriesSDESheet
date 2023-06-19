void fun(Node* root, Node* &prev, Node* &succ,int k)
    {
        if(root==NULL)  return;
        
        if(root->key > k)
        {
            if(succ==NULL)
            {
                succ = root;
            }
            else
            {
                if(succ->key > root->key)
                {
                    succ = root;
                }
            }
        }
        
        if(root->key < k)
        {
            if(prev==NULL)
            {
                prev = root;
            }
            else
            {
                if(prev->key < root->key)
                {
                    prev = root;
                }
            }
        }
        
        fun(root->left,prev,succ,k);
        
        fun(root->right,prev,succ,k);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = NULL;
        suc = NULL;
        
        fun(root,pre,suc,key);
    }
