void Fun(vector<int> &arr,int n,int ind,vector<int> &ans,int sum)
    {
        if(ind==n)
        {
            ans.push_back(sum);
            return;
        }
        
        Fun(arr,n,ind+1,ans,sum+arr[ind]);
        
        Fun(arr,n,ind+1,ans,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        
        Fun(arr,N,0,ans,0);
        
        return ans;
    }
