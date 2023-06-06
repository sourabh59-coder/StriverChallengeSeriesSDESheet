void dfs(int v,int parent,string &ans,vector<int> adj[],vector<int> &vis)
{
    vis[v] = 1;

    for(auto child:adj[v])
    {
        if(vis[child])
        {
            if(child!=parent)
            {
                ans = "Yes";
            }
        }
        else
        {
            dfs(child,v,ans,adj,vis);
        }
    }
}

string cycleDetection (vector<vector<int>>& v, int n, int m)
{
    vector<int> adj[n+1];
    for(int i=0;i<v.size();i++)
    {
        int v1 = v[i][0];
        int v2 = v[i][1];

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    string ans = "No";
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,ans,adj,vis);
        }
    }
    return ans;
}
