class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums2=nums;
        nums2.insert(nums2.end(), nums.begin(), nums.end());
        vector<int> ans(nums2.size());
        stack<int> st;
        for(int i=nums2.size()-1 ; i>=0 ; i--)
        {
            while(!st.empty( )&& nums2[i]>= st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=st.top();
            }

            st.push(nums2[i]);
        }
        ans.resize(nums.size());
        return ans; 
    }
};