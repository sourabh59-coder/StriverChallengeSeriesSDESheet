vector<int> topView(Node *root)
    {
        vector<int> res;
        
        map<int, Node*> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            Node* node = q.front().first;
            int v = q.front().second;
            q.pop();
            if(mp.find(v) == mp.end()) mp[v] = node;
            
            
            if(node->left) q.push({node->left, v-1});
            if(node->right) q.push({node->right, v+1});
            
        }
        
        for(const auto &i: mp) {
            res.push_back(i.second->data);
        }
        
        return res;
    }
