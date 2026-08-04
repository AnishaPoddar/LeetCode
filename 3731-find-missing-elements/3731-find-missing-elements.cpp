class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maximum=*max_element(nums.begin(), nums.end());
        int minimum=*min_element(nums.begin(), nums.end());
        if(maximum-minimum +1 == nums.size())
        {
            return {};
        }
        int l=maximum-minimum+1;
        vector<int> arr(l,0);
        vector<int> ans;
        for(int i=0 ; i< nums.size();i++)
        {
            arr[nums[i]-minimum]=1;
        }
        for(int i=0 ; i< arr.size();i++)
        {
            if(arr[i]==0)
            {
                ans.push_back(i+minimum);
            }
        }
        return ans;    
    }
};