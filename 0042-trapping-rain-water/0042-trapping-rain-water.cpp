class Solution {
public:
    void leftmax(vector<int>& height ,vector<int>& prefixmax)
    {
        int left_max=height[0];
        for(int i=0 ; i<height.size(); i++)
        {
            left_max = max(left_max, height[i]);
            prefixmax[i] = left_max;
        }
    }
    void rightmax(vector<int>& height, vector<int>& suffixmax)
    {
        int right_max=height[height.size()-1];
        for(int i=height.size()-1; i>=0; i--)
        {
            right_max=max(right_max, height[i]);
            suffixmax[i]=right_max;
        }
    }
    int trap(vector<int>& height) {
        int amount=0;
        vector<int> prefixmax(height.size());
        vector<int> suffixmax(height.size());
        leftmax(height, prefixmax);
        rightmax(height, suffixmax);
        for( int i=0 ; i< height.size(); i++)
        {
            int lm=prefixmax[i];
            int rm=suffixmax[i];
            if(lm > height[i] && rm > height[i])
            {
                amount+=min(lm,rm)-height[i];
            }
        }  
        return amount;
    }
};