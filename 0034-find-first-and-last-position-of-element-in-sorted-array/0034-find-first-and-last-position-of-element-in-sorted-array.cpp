class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=nums.size();
        int end=nums.size();
        int low=0;
        int high=nums.size()-1;
        vector<int> ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=target)
            {
                start=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        low = 0;
        high = nums.size() - 1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
            {
                end=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(start== nums.size() || nums[start]!=target )
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(start);
            ans.push_back((end-1));
        }
    return ans;

    }
};