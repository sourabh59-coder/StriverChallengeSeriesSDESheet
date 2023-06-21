class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        vector<int> vl(n,0),vr(n,0);
        int maxl = 0;
        for(int i=0;i<n;i++)
        {
            if(maxl<v[i])
            {
                maxl = v[i];
            }
            vl[i] = maxl;
        }
        maxl = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(maxl<v[i])
            {
                maxl = v[i];
            }
            vr[i] = maxl;
        }
        
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            ans += min(vr[i],vl[i])-v[i];
        }
        return ans;
    }
};
