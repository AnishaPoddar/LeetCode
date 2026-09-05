class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>&x , const vector<int>&y)
        {
            return x[1]<y[1];
        });
        int last=points[0][1];
        int count=1;
        for(int i=1 ; i<points.size(); i++)
        {
            if(points[i][0]>last)
            {
                last=points[i][1];
                count+=1;
            }
        }
        return count;
        
    }
};