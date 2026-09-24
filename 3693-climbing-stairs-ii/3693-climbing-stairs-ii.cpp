class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int> dp(n+1);
        dp[1]=cost[0]+1;
        if(n==1)
        {
            return dp[1];
        }
        dp[2]=min(cost[1]+4, cost[0]+cost[1]+2);
        if(n==2)
        {
            return dp[2];
        }
        dp[3]=min({cost[2]+9, cost[1]+4+cost[2]+1 , cost[0]+1 +cost[2]+4, cost[0] + 1 + cost[1] + 1 + cost[2] + 1});
        if(n==3)
        {
            return dp[3];
        }
        for(int i=4; i<=n ; i++)
        {
            dp[i]=min({dp[i-1]+ cost[i-1]+1, dp[i-2]+cost[i-1]+4 , dp[i-3]+cost[i-1]+9});
        }
        return dp[n];
        
    }
};