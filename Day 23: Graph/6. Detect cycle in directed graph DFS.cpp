private:
    bool dfs(int v,vector<int> adj[],vector<int> &vis,vector<int> &path)
    {
        vis[v] = 1;
        path[v] = 1;
        
        for(auto child: adj[v])
        {
            if(vis[child])
            {
                if(path[child]) return true;
            }
            else
            {
                if(dfs(child,adj,vis,path)) return true;
            }
        }
        path[v] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,path)) return true;
            }
        }
        
        return false;
    }
