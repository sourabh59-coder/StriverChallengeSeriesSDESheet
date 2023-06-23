 static bool cmp(pair<pair<int,int>,double> a, pair<pair<int,int>,double> b)
    {
        return  a.second>b.second;
    }
    
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       vector<pair<pair<int,int>,double>> v;
       
       double profit=0;
       
       for(int i=0;i<n;i++)
       {   
           double rate= (double)arr[i].value/(double)arr[i].weight;
           
           v.push_back({{arr[i].value,arr[i].weight},rate});
       }
       
       sort(v.begin(),v.end(),cmp);
       
       for(int i=0;i<n;i++)
       {
           if(W>v[i].first.second)
           {
               W=W-v[i].first.second;
               profit=profit+v[i].first.first;
           }
           
           else
           {   
               double rem=double(W*v[i].second);
               profit=profit+rem;
               break;
           }
       }
       
       return profit;
    }

