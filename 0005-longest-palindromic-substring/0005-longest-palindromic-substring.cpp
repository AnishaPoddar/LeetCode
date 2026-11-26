class Solution {
public:
    string longestPalindrome(string s) {
        string s1=s;
        reverse(s.begin(), s.end());

        int r_index=0;
        int c_index=0;
        int max_count=0;

        vector<vector<int>> dp(s.size(), vector<int> (s.size(),0));
        for(int i=0 ; i< s.size(); i++)
        {
            for(int j=0 ; j< s.size(); j++)
            {
                if(s[i]==s1[j])
                {
                    dp[i][j]=(i==0||j==0)? 1: 1+dp[i-1][j-1];
                    if(max_count < dp[i][j] && (i-dp[i][j]+1)==(s.size()-j-1))
                    {
                        max_count=dp[i][j];
                        r_index=i;
                        c_index=j;
                    }  
                }
            }
        }
        string ans="";
        while(r_index>=0 && c_index>=0 && dp[r_index][c_index]!=0)
        {
            ans.push_back(s[r_index]);
            r_index--;
            c_index--;
        }
        return ans;   
    }
};