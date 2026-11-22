class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        for(int i=1; i< dp.size(); i++)
        {
            for(int j=0 ; j<=i ; j++)
            {
                if(dp[j] && dict.count(s.substr(j,i-j))) // we cant just keep trac of the last index made true 
                {
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()];
        
    }
};