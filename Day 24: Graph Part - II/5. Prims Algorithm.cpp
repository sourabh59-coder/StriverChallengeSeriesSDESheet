#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int,int>> adj[N];
vector<int> vis(N,0);
vector<pair<int,int>> ans;
priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> qe;
int n,m;

int PrimsAlgorithm()
{
    int cost = 0;
    
    while(!qe.empty())
    {
        int wt = qe.top().first;
        int node = qe.top().second.first;
        int parent = qe.top().second.second;
        qe.pop();
        
        if(parent!=-1)
        {
            if(!vis[node])
            {
                ans.push_back({parent,node});
                cost += wt;
            }
        }
        
        for(auto child: adj[node])
        {
            int child_v = child.first;
            int child_wt = child.second;
            
            if(!vis[child_v])
            {
                qe.push({child_wt,{child_v,node}});
            }
        }
        
        vis[node] = 1;
    }
    
    return cost;
}

signed main()
{
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        
        adj[v1].push_back({v2,wt});
        adj[v2].push_back({v1,wt});
    }
    
    qe.push({0,{0,-1}});
    cout<<PrimsAlgorithm()<<endl;
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
    return 0;
}
