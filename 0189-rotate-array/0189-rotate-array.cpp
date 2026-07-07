class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size())
        {
            k=k%nums.size();
        }
        int n=nums.size()-k;
        vector<int> temp(n);
        for(int i=0; i< nums.size(); i++ )
        {
            if(i<n)
            {
                temp[i]=nums[i];
            }
            else
            {
                nums[i-n]=nums[i];
            }
        }
         for(int i = k; i < nums.size(); i++)
        {
            nums[i] = temp[i - k];
        }
    }
};

        

