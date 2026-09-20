class Solution {
    int count(vector<int>& nums, int element , int low , int high)
    {
        int count=0;
        for(int i=low ; i<=high ; i++)
        {
            if(nums[i]==element)
            {
                count++;
            }
        }
        return count;
    }
    int majority(vector<int>& nums, int low, int high)
    {
        if(low==high)
        {
            return nums[low];
        }
        int mid=low+(high-low)/2;
        int left_max=majority(nums , low , mid);
        int right_max=majority(nums , mid+1 , high);
        if(left_max==right_max)
        {
            return left_max;
        }
        int left_count=count(nums, left_max , low , high);
        int right_count=count(nums , right_max , low, high);

        return (left_count > right_count) ? left_max : right_max;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority( nums, 0 , nums.size()-1);    
    }
};