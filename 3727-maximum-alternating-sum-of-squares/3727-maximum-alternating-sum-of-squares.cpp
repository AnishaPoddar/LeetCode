class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        for(int i=0; i< nums.size(); i++)
        {
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int i=0;
        int j=nums.size()-1;
        long long sum=0;
        while(i<=j)
        {
            if(i==j)
            {
                sum+=nums[i];
            }
            else
            {
                sum+=nums[i]-nums[j];
            }
            i++;
            j--;

        }
        return sum;
        
    }
};