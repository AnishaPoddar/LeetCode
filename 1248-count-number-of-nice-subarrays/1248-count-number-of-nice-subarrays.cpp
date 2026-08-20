class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd_count=0;
        int count=0;
        int j=0;
        int even=0;
        for(int i=0 ; i< nums.size(); i++)
        {
            if(nums[i]%2!=0)
            {
                odd_count+=1;
                even = 0;
            }
            while( odd_count == k)
            {
                even++;
                if(nums[j]%2!=0)
                {
                    odd_count-=1;
                }
                j++;
            }
            count+=even;
        }
        return count;
    }
};