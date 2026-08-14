class Solution {
public:
    int no_of_days(vector<int>& weights, int n)
    {
        int days=0;
        int sum=0;
        for(int i=0 ; i< weights.size() ; i++)
        {
            sum+=weights[i];
            if(sum==n)
            {
                days++;
                sum=0;
            }
            else if( sum > n)
            {
                sum=0;
                days++;
                i--;
            }
        }
        if(sum > 0)
           days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int sum=0;
        for(int i=0 ; i< weights.size(); i++)
        {
            sum+=weights[i];
        }
        int high=sum;
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int day=no_of_days(weights, mid);
            if( day <= days)
            {
                 ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }  
        return ans;  
    }
};