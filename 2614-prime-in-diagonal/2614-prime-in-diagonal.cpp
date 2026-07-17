class Solution {
public:
    int Prime(int n)
    {
        if(n<=1)
        {
            return -1;
        }
        for(int i=2; i*i<=n ; i++)
        {
            if(n%i==0)
            {
                return -1;
            }
        }
        return 1;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int max_prime=0;
        for(int i=0 ; i<nums.size(); i++)
        {
            if(Prime(nums[i][i])==1 && nums[i][i]>max_prime)
            {
                max_prime=nums[i][i];
            }
            if(Prime(nums[i][nums.size()-i-1])==1 && nums[i][nums.size()-i-1]>max_prime)
            {
                max_prime=nums[i][nums.size()-i-1];
            }
        }
        return max_prime;     
    }
};