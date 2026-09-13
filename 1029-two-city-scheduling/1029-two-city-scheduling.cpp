class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector<int> &a ,const vector<int> &b){
            return (a[1] - a[0]) < (b[1] - b[0]);
        });
        int totalcost=0;
        int i;
        for( i=0; i<costs.size()/2; i++)
        {
            totalcost+=costs[i][1];
        }
        for(int j=i ; j<costs.size(); j++)
        {
            totalcost+=costs[j][0];
        }
        return totalcost;
    
    }
};