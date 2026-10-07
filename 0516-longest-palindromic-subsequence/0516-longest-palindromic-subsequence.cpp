class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(), s.end());
        int m=s.size();
        vector<vector<int>> dp(m , vector<int> (m));
        dp[0][0]=s2[0]==s[0]?1:0;
        for(int i=1; i< m ; i++)
        {
            dp[0][i]=(s[0]!=s2[i])?dp[0][i-1]:1;
        }
        for(int j=1 ; j< m ; j++)
        {
            dp[j][0]=s2[0]!=s[j]?dp[j-1][0]:1;
        }
        for(int i=1; i< m ; i++)
        {
            for(int j=1 ; j<m ; j++)
            {
                if(s[i]==s2[j])
                {
                    dp[i][j]=1+dp[i-1][j-1];              
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
        }
        }
        return dp[m-1][m-1];


        
    }
};