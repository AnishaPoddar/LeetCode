class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> freq(101, 0);
        for(int i=0 ; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        int i;
        for( i=k; i<=100; i+=k)
        {
            if(freq[i]==0)
            {
                return i;
            }
        }
        return i; 
    }
};