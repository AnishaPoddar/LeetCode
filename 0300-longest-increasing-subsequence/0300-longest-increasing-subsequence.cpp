class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_len=0;
        vector<int> dp(nums.size(),1);
        for(int i=0 ; i< nums.size(); i++)
        {
            for(int j=0; j<i ; j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[j]+1, dp[i]);
                }
            }
        }
        for(int i=0 ; i<nums.size(); i++)
        {
            max_len=max(max_len, dp[i]);
        }
        return max_len;  
    }
};