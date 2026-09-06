class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x , const vector<int>&y)
        {
            return x[0]<y[0];
        });
        vector<vector<int>> groups;
        groups.push_back(intervals[0]);
        int last=groups[0][1];
        for(int i=1; i< intervals.size(); i++)
        {
            if(intervals[i][0]<=last)
            {
                groups[groups.size()-1][1] =max(last, intervals[i][1]);
                last = groups[groups.size()-1][1];
            }
            else
            {
                groups.push_back(intervals[i]);
                last=intervals[i][1];
            }
        }
        return groups;
        
    }
};