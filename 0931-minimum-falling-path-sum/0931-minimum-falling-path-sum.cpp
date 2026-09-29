class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m , vector<int> (n));
        for(int i=0; i< n ; i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1; i< m ; i++)
        {
            for(int j=0; j< n ; j++)
            {
                int left=(j>0)?dp[i-1][j-1]:INT_MAX;
                int mid=dp[i-1][j];
                int right=(j<n-1)?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=min({left,mid, right})+matrix[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0 ; i< n ; i++)
        {
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};