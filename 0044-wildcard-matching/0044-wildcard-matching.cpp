class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1));
        dp[0][0]=true;
        for(int i=1 ; i<=n ; i++)
        {
            if (p[i - 1] == '*') {
                dp[i][0] = dp[i-1][0];
            }
            else
            {
                dp[i][0] = false;
            }
        }
        for(int i=1 ; i<=m ; i++)
        {
            dp[0][i]=false;
        }

        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(p[i-1]==s[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else 
                {
                    if(p[i-1]=='*')
                    {
                        dp[i][j]=dp[i-1][j] || dp[i][j-1];
                    }
                    else if(p[i-1]=='?')
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                
            }
        }
        return dp[n][m];
        
    }
};