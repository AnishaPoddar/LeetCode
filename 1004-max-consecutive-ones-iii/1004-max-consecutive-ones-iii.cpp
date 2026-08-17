class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> freq(2,0);
        int j=0;
        int ans=0;
        for(int i=0 ; i< nums.size(); i++)
        {
            freq[nums[i]]++;
            while( freq[0] > k)
            {
                freq[nums[j]]--;
                j++;
            }
            ans=max(ans, i-j+1);
        }
        return ans; 
    }
};