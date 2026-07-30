class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reached=0;
        for(int i=0 ; i< nums.size(); i++)
        {
            if(i>max_reached)
            {
                return false;
            }
            if((i+nums[i])> max_reached)
            {
                max_reached=i+nums[i];
            }
        }
        if(max_reached >= nums.size()-1)
        {
            return true;
        }
        return false;   
    }
};