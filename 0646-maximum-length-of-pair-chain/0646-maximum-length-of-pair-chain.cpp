class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int>&x, const vector<int>&y)
        {
            return x[1]<y[1];
        });
        int count=1;
        int last=pairs[0][1];
        for(int i=1; i< pairs.size();i++)
        {
            if(pairs[i][0] > last)
            {
                count++;
                last=pairs[i][1];
            }
        }
        return count;    
    }
};