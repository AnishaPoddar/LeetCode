class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        vector<int > output;
        for(int i=0 ; i< nums.size(); i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                output.push_back(mp[target-nums[i]]);
                output.push_back(i);
                break;
            }
            else
            {
                mp[nums[i]]=i;
            }

        }
        return output;
        
        
    }
};