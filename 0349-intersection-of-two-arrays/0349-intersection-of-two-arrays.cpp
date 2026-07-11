class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mp;
        vector<int> intersect;
        for(int i=0 ; i<nums1.size(); i++)
        {
            mp[nums1[i]]=0;
        }
        for(int i=0 ; i<nums2.size(); i++)
        {
            if(mp.find(nums2[i])!=mp.end()  && mp[nums2[i]]==0) 
            {
                mp[nums2[i]]--;
                intersect.push_back(nums2[i]);
            
            }
            
        }
        return intersect;
        
    }
};