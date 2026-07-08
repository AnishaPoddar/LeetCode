class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int key=nums[0];
        for(int i=1 ; i< nums.size(); i++)
        {
            int j;
            for( j=i; j<nums.size() ; j++)
            {
                if(nums[j]!=key)
                {
                    k++;
                    key=nums[j];
                    break;
                }
            }

            if(j == nums.size())   
                break;

            swap(nums[k], nums[j]);
            i=j;
        }
        return k+1;
        
    }
};