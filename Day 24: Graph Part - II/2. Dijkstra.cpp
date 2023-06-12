#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;
int n,m;
vector<pair<int,int>> adj[N];
vector<int> ans(N,INF);

void Dijkstra(int source)
{
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;
    
    ans[source] = 0;
    qe.push({0,source});
    
    while(!qe.empty())
    {
        int parent =  qe.top().second;
        int dist = qe.top().first;
        qe.pop();
        
        for(auto child: adj[parent])
        {
            int child_v = child.first;
            int child_wt = child.second;
            
            if(ans[parent]+child_wt < ans[child_v])
            {
                ans[child_v] = ans[parent]+child_wt;
                qe.push({ans[child_v],child_v});
            }
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
        
        adj[v1].push_back({v2,wt});
    }
    
    Dijkstra(1);
    
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" : "<<ans[i]<<endl;
    }
    
    return 0;
}
