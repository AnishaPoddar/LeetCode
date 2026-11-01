class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, INT_MAX));
        for(int i=0 ; i< coins.size(); i++)
        {
            dp[i][0]=0;
        }
        for(int i=1 ; i<=amount ; i++)
        {
            dp[0][i]=i % coins[0] == 0?i / coins[0]:INT_MAX;
        }
        for(int i=1; i< coins.size(); i++)
        {
            for(int j=1 ; j<=amount ; j++)
            {
                int not_take=dp[i-1][j];
                int take=INT_MAX;
                if(j>=coins[i] && dp[i][j - coins[i]] != INT_MAX)
                {
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(take , not_take);
            }
        }
        return (dp[coins.size()-1][amount] >= INT_MAX) ? -1 : dp[coins.size()-1][amount];
        
    }
};