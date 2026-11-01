class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        if (totalSum - diff < 0 || (totalSum - diff) % 2 != 0) {
            return 0;
        }
        int K = (totalSum - diff) / 2;
        vector<vector<int>> dp(arr.size(), vector<int> (K+1,-1));
        for(int i=0 ; i< arr.size(); i++)
        {
            int mult = arr[i]==0 ? 2 : 1;
            dp[i][0] = (i==0 ? mult : dp[i-1][0]*mult);
        }
        for(int i=1 ; i<=K ; i++)
        {
            dp[0][i]=arr[0]==i?1:0;
        }
        for(int i=1 ; i< arr.size(); i++)
        {
            for(int j=1; j<=K ; j++)
            {
                int exclude=dp[i-1][j];
                int include=0;
                if(arr[i]<=j)
                {
                    include=dp[i-1][j-arr[i]]; 
               }
               dp[i][j]=(include + exclude);

            }
        }
        return dp[arr.size() - 1][K];
        
        
    }
};