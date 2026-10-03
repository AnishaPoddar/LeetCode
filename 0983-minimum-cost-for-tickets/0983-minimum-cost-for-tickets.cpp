class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> is_travel_day(days.begin(), days.end());
        int max_ele=*max_element(days.begin(), days.end());
        vector<int> dp(max_ele+1);
        dp[0]=0;
        for(int i=1; i<dp.size(); i++)
        {
            if (is_travel_day.find(i) == is_travel_day.end()) {
                dp[i] = dp[i - 1];
                continue;
            }
            int buy1=dp[i-1]+costs[0];
            int buy7=dp[max(0,i-7)]+costs[1];
            int buy30=dp[max(0,i-30)]+costs[2];
            dp[i]=min({buy1, buy7, buy30});
        }
        return dp[dp.size()-1];
    }
};