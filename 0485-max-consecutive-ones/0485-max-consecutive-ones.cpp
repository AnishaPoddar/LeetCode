class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0 ; 
        int maxcount=0;
        for(int i=0 ; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                count=1;
                for(int j=i+1 ; j<nums.size() ; j++)
                {
                    if(nums[j]==1)
                    {
                        count++;
                        if(count==nums.size())
                        {
                            i=j-1;
                        }
                    }
                    else
                    {
                        i=j;
                        break;
                    }
                }
                if(count>maxcount)
                {
                    maxcount=count;
                }
            }
        }
        return maxcount;
        
    }
};