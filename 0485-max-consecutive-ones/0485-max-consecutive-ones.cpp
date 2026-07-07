class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0 ; 
        int maxcount=0;
        for(int i=0 ; i<nums.size(); i++)
        {
            if(nums[i]!=1)
            {
                maxcount=max(maxcount, count);
                count=0;
            }
            else
            {
                count=count+1;
            }
        }
        return max(maxcount, count);
        
    }
};