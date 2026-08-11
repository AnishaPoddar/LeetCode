class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_element=5001;
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            min_element=min(min_element, nums[mid]);
            if(nums[mid]> nums[low])
            {
                if(nums[low]> nums[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            else
            {
                if(mid==low)
                {
                    low=low+1;
                }
                else
                {
                    high=mid-1;
                }
            } 
        }
        return min_element;    
    }
};