class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int max_len=1;
        int last_index=0;
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size());
        sort(nums.begin(), nums.end());
        for(int i=0; i< nums.size(); i++)
        {   
            hash[i]=i;
            for(int j=0; j< i; j++)
            {
                if(nums[i]%nums[j]==0 && dp[i] < dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if( dp[i] > max_len)
            {
                max_len=dp[i];
                last_index=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last_index]);
        while(hash[last_index]!=last_index)
        {
            ans.push_back(nums[hash[last_index]]);
            last_index=hash[last_index];
        }
        return ans;
    }
};