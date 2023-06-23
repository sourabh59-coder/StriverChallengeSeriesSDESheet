static bool comp(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int ans[n];
        memset(ans, -1, sizeof(ans));
        sort(arr,arr+n,comp);
        
        for(int i=0;i<n;i++)
        {
            int deadline=arr[i].dead;
            if(ans[deadline-1]==-1)
            {
                ans[deadline-1]=arr[i].profit;
            }
            
            else
            {
                while(deadline>0)
                {
                    if(ans[deadline-1]==-1)
                    {
                        ans[deadline-1]=arr[i].profit;
                        break;
                    }
                    deadline--;
                }
            }
        }
        
        int count=0;
        int max_profit=0;
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            if(ans[i]!=-1)
            {
                count++;
                max_profit=max_profit+ans[i];
            }
        }
        temp.push_back(count);
        temp.push_back(max_profit);
        return temp;
    } 
