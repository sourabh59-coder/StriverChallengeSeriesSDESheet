 #include <bits/stdc++.h>
using namespace std;

void fun(vector<int> &A,int n,vector<int> &ans)
{
    stack<int> st;
    
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            if(st.top()<A[i])
            {
                ans.push_back(st.top());
            }
            else
            {
                while(!st.empty() && st.top()>=A[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top());
                }
            }
        }
        
        st.push(A[i]);
    }
}

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans;
    fun(A,A.size(),ans);
    return ans;
}
