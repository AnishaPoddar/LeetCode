class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int max_len=1;
        sort(words.begin(), words.end(), [](string a , string b)
        {
            return a.length() < b.length();
        });
        vector<int> dp(words.size(),1);
        for(int i=0 ; i< words.size(); i++)
        {
            for(int j=0 ; j< i ; j++)
            {
               if( words[j].length()+1==words[i].length())
               {
                int count=0;
                int index1=0;
                int index2=0;
                while(index2< words[j].size() && index1< words[i].size())
                {
                    if(words[j][index2]!=words[i][index1])
                    {
                        count++;
                        index2--;
                    }
                    index1++;
                    index2++;
                }
                if(count<=1 && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    max_len=max(max_len,dp[i]);
                }
               }
            }
        }
        return max_len;
    }
};