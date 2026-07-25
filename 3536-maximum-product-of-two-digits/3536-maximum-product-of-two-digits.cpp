class Solution {
public:
    int maxProduct(int n) {
        int max=INT_MIN;
        int second_max=INT_MIN;
        while(n>0)
        {
            int r=n%10;
            if(r >= max)
            {
                second_max=max;
                max=r;
            }
            else if(r >= second_max)
            {
                second_max=r;
            }
            n=n/10;
        }
        return (max* second_max);
    
        
    }
};