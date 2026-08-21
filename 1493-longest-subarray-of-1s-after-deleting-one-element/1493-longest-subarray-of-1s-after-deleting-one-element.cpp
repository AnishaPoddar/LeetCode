class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int zero_count=0;
        int j=0;
        for(int i=0 ; i< nums.size(); i++)
        {
            if(nums[i]==0)
            {
                zero_count+=1;
            }
                while(zero_count > 1 )
                {
                    if(nums[j]==0)
                    {
                        zero_count-=1;
                    }
                    j++;
                }  
            ans=max(ans , i-j);
        }   
        return (ans);
    }
};