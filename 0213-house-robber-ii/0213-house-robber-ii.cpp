class Solution {
public:
    int rob2(vector<int>& nums, int low, int n)
    {
        int len=n-low+1;
        if (len == 1) return nums[low];
        vector<int> dp(len);
        dp[0]=nums[low];
        dp[1]=max(nums[low], nums[low+1]);
        for(int i=2 ; i< len; i++ )
        {
            dp[i]=max(dp[i-1], dp[i-2]+nums[low+i]);
        }
        return dp[len-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }
        return max(rob2(nums, 0 , nums.size()-2), rob2(nums, 1 , nums.size()-1));
    }
};