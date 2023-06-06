class Solution {
  public:
  void DFS(int v,vector<int> adj[],vector<int> &ans,vector<bool> &vis)
  {
      ans.push_back(v);
      vis[v] = true;
      
      for(auto child: adj[v])
      {
          if(!vis[child])
          {
              DFS(child,adj,ans,vis);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        // int N = 1e5;
        vector<bool> vis(V+1,false);
        DFS(0,adj,ans,vis);
        
        return ans;
    }
};
