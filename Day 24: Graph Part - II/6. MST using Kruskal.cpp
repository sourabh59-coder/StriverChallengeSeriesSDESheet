#include <bits/stdc++.h>
#define int long  long
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;
int n,m;
vector<pair<int,pair<int,int>>> edges;
int parent[N];
int sz[N];


void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    if(v==parent[v])    return v;
    
    return parent[v] = find(parent[v]);
}

void Union(int x,int y)
{
    x = parent[x];
    y = parent[y];
    
    if(x!=y)
    {
        if(sz[x]<sz[y]) swap(x,y);
        parent[y] = x;
        sz[x] += sz[y]; 
    }
}

int KruskalsAlgo()
{
    int cost = 0;
    
    for(auto &edge: edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if(find(v)==find(u))
        {
            continue;
        }
        
        Union(u,v);
        cost += wt;
        cout<<u<<" "<<v<<endl;
    }
    
    return cost;
}

signed main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        make(i);
    }
    
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        
        edges.push_back({wt,{u,v}});
    }
    
    sort(edges.begin(),edges.end());
    
    cout<<KruskalsAlgo()<<endl;
    
    return 0;
}
