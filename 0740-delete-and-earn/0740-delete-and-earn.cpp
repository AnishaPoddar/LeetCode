class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_ele=*max_element(nums.begin(), nums.end());
        vector<int> freq(max_ele+1, 0);
        for(int i=0 ; i< nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        int prev2=0;
        int prev1=1*freq[1];
        for(int i=2 ; i< freq.size(); i++)
        {
            int curr=max(prev1, prev2+ i*freq[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;

    }
};