void dfs(int i,int vis[],vector<int>&ans, vector<int> adj[]){
       for(auto x:adj[i]){
           if(vis[x]==0)
           dfs(x,vis,ans,adj);
        }
        
 
               vis[i]=1;
               ans.push_back(i);
              
         
       }
 
vector<int> topoSort(int V, vector<int> adj[]) 
{
 
   int i=0;
   int vis[V]={0};
   vector<int>ans;
   while(i<V){
       if(vis[i]==0)
       dfs(i,vis,ans,adj);
       i++;
   }
  reverse(ans.begin(), ans.end());
   
   return ans;
}
