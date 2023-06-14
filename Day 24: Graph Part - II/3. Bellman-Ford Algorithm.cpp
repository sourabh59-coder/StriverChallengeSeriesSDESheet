#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;
int n,m;
vector<vector<int>> edges;
vector<int> ans(N,INF);

void BellmanFordAlgorithm(int source)
{
    ans[source] = 0;
    
    for(int i=0;i<n-1;i++)
    {
        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(ans[u] != INF && ans[u]+wt<ans[v])
            {
                ans[v] =  ans[u]+wt;
            }
        }
    }
    
    for(auto edge: edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        if(ans[u]!=INF && ans[u]+wt<ans[v])
        {
            cout<<"Negative cycle exists"<<endl;
        }
    }
}

signed main()
{
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        edges.push_back({v1,v2,wt});
    }
    
    BellmanFordAlgorithm(0);
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<" : "<<ans[i]<<endl;
    }
    
    return 0;
}
