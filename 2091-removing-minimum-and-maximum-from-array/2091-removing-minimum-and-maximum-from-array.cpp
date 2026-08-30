class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size()<=2)
        {
            return nums.size();
        }
        int minele=INT_MAX;
        int minindex=-1;
        int maxindex=-1;
        int maxele=INT_MIN;
        for(int i=0 ; i<nums.size(); i++)
        {
            if(nums[i]<minele)
            {
                minele=nums[i];
                minindex=i;
            }
            if(nums[i]>maxele)
            {
                maxele=nums[i];
                maxindex=i;
            }
        }
        int i=min(minindex, maxindex);
        int j=max(maxindex, minindex);

        int front=j+1;
        int back=nums.size()-i;
        int mixed=(i+1)+(nums.size()-j);

        return min({front,back,mixed});
    }
};