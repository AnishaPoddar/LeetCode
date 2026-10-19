class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count=0;
        int t_count=0;
        vector<int> ans;
        for(int i=0 ; i< nums.size(); i++)
        {
            if(nums[i]< target)
            {
                count++;
            }
            else if(nums[i]==target)
            {
                t_count++;
            }
        }
        for(int i=0; i< t_count ; i++)
        {
            ans.push_back(count++);
        }
        return ans;
    }
};