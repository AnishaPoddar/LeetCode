class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i=0; i< stones.size(); i++)
        {
            sum+=stones[i];
        }
        vector<vector<bool>> dp(stones.size(), vector<bool> (sum+1));
        for(int i=0 ; i< stones.size(); i++)
        {
            dp[i][0]=true;
        }
        for(int i=1 ; i< sum+1; i++)
        {
            dp[0][i]=stones[0]==i?true : false;

        }
        for(int i=1 ; i< stones.size(); i++)
        {
            for(int j=1 ; j<=sum; j++)
            {
                bool nottake=dp[i-1][j];
                bool take=false;
                if(j>=stones[i])
                {
                    take=dp[i-1][j-stones[i]];
                }
                dp[i][j]=take||nottake;
        }
        }
	
    int min_dif=INT_MAX;
    for(int i=0 ; i<=sum/2; i++)
    {
        if(dp[stones.size()-1][i]==true)
        {
            int s1=i;
            int s2=sum-s1;
            min_dif=min(min_dif, abs(s1-s2));
        }
    }
    return min_dif;
    }
};