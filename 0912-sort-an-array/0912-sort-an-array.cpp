class Solution {
public:
    void merge(vector<int>& nums, int low , int mid , int high)
    {
        vector<int> ans;
        int i=low ; 
        int j=mid+1;
        while(i<=mid && j<=high)
        {
            if(nums[i]<= nums[j])
            {
                ans.push_back(nums[i]);
                i++;
            }
            else if(nums[i]> nums[j])
            {
                ans.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid)
        {
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=high)
        {
            ans.push_back(nums[j]);
            j++;
        }
        for(int k = low; k <= high; k++)
        {
         nums[k] = ans[k - low];
        }
    }
    void merge_sort(vector<int>& nums, int low, int high)
    {
        if(low>=high)
        {
            return;
        }
        int mid=(low+high)/2;
        merge_sort(nums , low, mid);
        merge_sort(nums, mid+1, high);
        merge(nums , low , mid , high);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0 , nums.size()-1 );
        return nums;
  
    }
};