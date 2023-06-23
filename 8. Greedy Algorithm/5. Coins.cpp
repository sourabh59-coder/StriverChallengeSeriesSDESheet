#include <bits/stdc++.h>
// #define int long long
using namespace std;

vector<int> coins{1000,500,100,50,20,10,5,2,1};    

int fun(int n)
{
    int cnt = 0;
    for(int i=0;i<coins.size();i++)
    {
        int val = (n/coins[i]);
        cnt += val;
        n = n-(val*coins[i]);
    }
    return cnt;
}

signed main()
{
    int n;
    cin>>n;
    
    cout<<fun(n)<<endl;
    
    return 0;
}
