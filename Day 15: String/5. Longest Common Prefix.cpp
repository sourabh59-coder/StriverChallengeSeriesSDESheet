class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();//number of elements in vector --> number of string
        int m = s[0].length();//string length 
        
        if(s.size()==0)
        {
            return "";
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i>=s[j].size() ||s[0][i]!=s[j][i])
                {
                    return s[0].substr(0,i);
                }
            }
        }
        return s[0];
    }
};
