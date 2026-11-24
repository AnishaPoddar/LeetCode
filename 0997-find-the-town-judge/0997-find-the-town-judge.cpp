class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n+1);
        for(int i=0; i< trust.size(); i++)
        {
            int u=trust[i][0];
            int v=trust[i][1];
            arr[u]--;
            arr[v]++;
        }
        for(int i=1 ; i<=n ; i++)
        {
            if(arr[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};