class Solution {
public:
    bool isPrime(int x)
    {
        if(x < 2) return false;

        for(int i = 2; i * i <= x; i++)
        {
            if(x % i == 0)
                return false;
        }

        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int i=0 ; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0 ; i<nums.size(); i++)
        {
            if(isPrime(mp[nums[i]]))
            {
                return true;
            }

        }
        return false;    
    }
};