class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(),0));
        dp[0][0]=matrix[0][0]-'0';
        int max_len=dp[0][0];
        for(int i=1; i< matrix[0].size(); i++)
        {
            dp[0][i]=matrix[0][i]-'0';
            max_len=max(max_len, dp[0][i]);
        }
        for(int j=1; j< matrix.size(); j++)
        {
            dp[j][0]=matrix[j][0]-'0';
            max_len=max(max_len, dp[j][0]);
        }
        for(int i=1; i< matrix.size(); i++)
        {
            for(int j=1; j< matrix[0].size(); j++)
            {
                if(matrix[i][j]=='1')
                {
                dp[i][j]=min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                max_len=max(max_len, dp[i][j]);
                }
            }
        }
        return max_len*max_len;
    }
};