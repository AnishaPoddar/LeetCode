class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned int>> dp(coins.size(), vector<unsigned int> (amount+1,0));
        dp[0][0]=1;
        for(int i=1 ; i< coins.size(); i++)
        {
            dp[i][0]=1;
        }
        for(int i=1 ; i<=amount; i++)
        {
            dp[0][i]=coins[0]>0 && i%coins[0]==0?1:0;
        }
        for(int i=1 ; i<coins.size(); i++)
        {
            for(int j=1 ; j<=amount ; j++)
            {
                unsigned int not_take=dp[i-1][j];
                unsigned int take=0;
                if(j>=coins[i])
                {
                    take=dp[i][j-coins[i]];
                }
                dp[i][j]=take+not_take;
            }
        }
        return dp[coins.size()-1][amount];
    }
};