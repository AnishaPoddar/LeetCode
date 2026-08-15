class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        double min_price=0.0;
        for(int i=0 ; i< prices.size();i++)
        {
            if(i< discounts.size())
            {
                min_price+=(prices[i]*(100-discounts[i]))/100.0;
            }
            else
            {
                min_price+=prices[i];
            }
        }
        return min_price;
    }
};