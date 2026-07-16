class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
            prefixGcd.push_back(gcd(nums[i],maxi));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i=0;
        int j=prefixGcd.size()-1;
        long long sum=0;
        while(i<j)
        {
            sum=sum+gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
    return sum;  
    }
};