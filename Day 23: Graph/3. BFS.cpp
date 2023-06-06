vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        vector<int> vis(V+1,0);
        
        vis[0] = 1;
        ans.push_back(0);
        queue<int> qe;
        qe.push(0);
        
        while(!qe.empty())
        {
            int node = qe.front();
            qe.pop();
            
            for(auto child: adj[node])
            {
                if(!vis[child])
                {
                    qe.push(child);
                    ans.push_back(child);
                    vis[child] = 1;
                }
            }
        }
        
        return ans;
    }
