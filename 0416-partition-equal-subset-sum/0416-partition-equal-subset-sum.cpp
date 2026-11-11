class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0 ; i< nums.size(); i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        vector<vector<bool>> dp(nums.size(), vector<bool> ((sum/2)+1));
        for(int i=0 ; i<=sum/2; i++)
        {
            dp[0][i]=nums[0]==i?true:false;
        }
        for(int i=0 ; i<nums.size(); i++)
        {
            dp[i][0]=true;
        }
        for(int i=1 ; i<nums.size(); i++)
        {
            for(int j=1 ;j<=sum/2; j++)
            {
                bool not_take=dp[i-1][j];
                bool take = false;
                if (j >= nums[i]) {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = not_take || take;
            }
        }
        return dp[nums.size()-1][sum/2];  
    }
};