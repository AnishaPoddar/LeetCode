class Solution {
public:
    int sumlessthan(vector<int>& nums, int goal)
    {
        if(goal<0)
        {
            return 0;
        }
        int left=0;
        int sum=0;
        int count=0;
        for(int i=0 ; i< nums.size(); i++)
        {
            sum+=nums[i];
            while(sum> goal)
            {
                sum-=nums[left];
                left++;
            }
            count+=i-left+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumlessthan(nums, goal)-sumlessthan(nums, goal-1);
    }
};