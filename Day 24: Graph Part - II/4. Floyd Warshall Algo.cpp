#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+10;
const int INF = 1e9+10;
int n,m;
vector<pair<int,int>> adj[N];
vector<vector<int>> ans(N, vector<int> (N, INF));

void FloydWarshallAlgo()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                ans[i][j] = 0;
            }
        }
    }
    
    for(int via=0;via<n;via++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j] = min(ans[i][j],ans[i][via]+ans[via][j]);
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(ans[i][j]<0)
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
        
        adj[v1].push_back({v2,wt});
        ans[v1][v2] = wt;
    }
    
    FloydWarshallAlgo();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}
