class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2 ; i< nums.size(); i++)
        {
            if(arr1.back()> arr2.back())
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }
        }
        int m=arr1.size();
        int l=arr2.size();
        for(int i=0 ; i< m ; i++)
        {
            nums[i]=arr1[i];
        }
        for(int i=m ; i<m+l ; i++)
        {
            nums[i]=arr2[i-m];
        }
        return nums;  
    }
};