vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mp;
        vector<int> ans;
        if(root==NULL)  return ans;
        
        queue<pair<Node* , int>> qe;
        qe.push({root,0});        
        
        while(!qe.empty())
        {
            auto node = qe.front();
            qe.pop();
            
            mp[node.second] = node.first->data;
            
            if(node.first->left)
            {
                qe.push({node.first->left,node.second-1});
            }
            
            if(node.first->right)
            {
                qe.push({node.first->right,node.second+1});
            }
        }
        
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
