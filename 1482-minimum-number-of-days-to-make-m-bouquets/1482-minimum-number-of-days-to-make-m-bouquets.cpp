class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if(1LL* m*k > bloomDay.size())
        {
            return -1;
        }
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=0;
            int c=0;
            for(int i=0 ; i< bloomDay.size(); i++)
            {
                if(bloomDay[i]<= mid)
                {
                    c++;
                    if(c==k)
                {
                    count++;
                    c=0;
                }
                }
                else
                {
                    c=0;
                }
            }
            if( count >=m )
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
        
    }
};