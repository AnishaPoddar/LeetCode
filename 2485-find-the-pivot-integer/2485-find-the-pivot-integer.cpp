class Solution {
public:
    int pivotInteger(int n) {
        int low=1;
        int high=n ;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            double sum1=(mid*(mid+1))/2;
            double sum2=(n*(n+1))/2 - sum1 + mid ;
            if(sum1==sum2)
            {
                return mid;
            }
            else if( sum1 > sum2)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;

            }
        }
        return -1;
    }
};