class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int freq=INT_MIN;
        int len=INT_MAX;
        for(int i=0 ; i< nums.size(); i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=vector<int>(3,0);
            }
            mp[nums[i]][0]++;
            if(mp[nums[i]][0]==1)
            {
                mp[nums[i]][1]=i;
                mp[nums[i]][2]=0;
            }
            else
            {
                mp[nums[i]][2]=i-mp[nums[i]][1];
            }
        }
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(mp[nums[i]][0] > freq) 
            {
                len=mp[nums[i]][2];
                freq = mp[nums[i]][0];
            }
            else if(mp[nums[i]][0]== freq && mp[nums[i]][2]< len)
            {
                len=mp[nums[i]][2];
            }
        }
        return len+1;
    }
};