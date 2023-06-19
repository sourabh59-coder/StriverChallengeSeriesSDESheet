/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> um;

        int sum=0,len=0;

        for(int i=0;i<n;i++)

        {

            sum+=A[i];

            if(sum==0)

                len=i+1;

            else if(um.find(sum)!=um.end())

                len=max(len,i-um[sum]);

            else

                um[sum]=i;

        }

        return len;


    }
};
