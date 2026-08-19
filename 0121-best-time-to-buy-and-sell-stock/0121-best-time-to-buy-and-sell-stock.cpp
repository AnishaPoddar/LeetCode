class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_number=prices[0];
        int profit=0;
        for(int i=0 ; i< prices.size(); i++)
        {
            min_number=min(min_number , prices[i]);
            profit=max(profit , prices[i]-min_number);
        }
        return profit;
        
    }
};