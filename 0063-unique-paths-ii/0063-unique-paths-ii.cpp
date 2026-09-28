class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int> (obstacleGrid[0].size()));
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        dp[0][0]=(obstacleGrid[0][0]==1)?0:1;
        for(int i=1 ; i<n ; i++)
        {
            dp[0][i]=(obstacleGrid[0][i]==0)?dp[0][i-1]:0;
        }
        for(int j=1; j<m ; j++)
        {
            dp[j][0]=(obstacleGrid[j][0]==0)?dp[j-1][0]:0;
        }
        for(int i=1 ; i< m; i++)
        {
            for(int j=1; j<n; j++)
            {
                dp[i][j]=(obstacleGrid[i][j]==1)?0:(dp[i-1][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];    
    }
};