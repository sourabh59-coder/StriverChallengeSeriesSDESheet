#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;
vector<int> adj[N];
vector<int> vis(N,0);
vector<int> ans;
vector<int> degree(N,0);
int cnt = 0;

void TopologicalSort(int n)
{
    queue<int> qe;
    for(int i=0;i<n;i++)
    {
        if(degree[i]==0)
        {
            qe.push(i);
        }
    }
    
    while(!qe.empty())
    {
        int front = qe.front();
        qe.pop();
        ans.push_back(front);
        
        for(auto child: adj[front])
        {
            degree[child]--;
            if(degree[child]==0)
            {
                qe.push(child);
            }
        }
        cnt++;
    }
}

signed main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        
        adj[v1].push_back(v2);
        degree[v2]++;
    }
    
    TopologicalSort(n);
    
    if(cnt==n)
    {
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"Graph is not Acyclic Directed Graph"<<endl;
    }
    
    return 0;
}
