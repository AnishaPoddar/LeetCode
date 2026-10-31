class Solution {
public:
    bool partition(int n , vector<int>& nums, vector<vector<int>>& dp, int target)
    {
        if(target==0)
        {
            return true;
        }
        if(n==0 )
        {
            return nums[n]==target;
        }
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        bool take=false;
        bool nottake=partition(n-1, nums, dp , target);
        if(target>=nums[n])
        {
            take=partition(n-1, nums , dp , target-nums[n]);
        }
        dp[n][target]=take|| nottake;
        return dp[n][target];
    }
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
        int target=sum/2;
        vector<vector<int>> dp(nums.size(), vector<int> (target+1, -1));
        return partition(nums.size()-1 , nums , dp, target);
        
    }
};