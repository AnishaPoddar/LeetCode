class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> ans(26, 0);
        int maxfreq=0;
        int maxlen=0;
        int j=0;
        for(int i=0 ; i< s.size(); i++)
        {
            ans[s[i]-'A']++;
            maxfreq=max(maxfreq, ans[s[i]-'A']);
            while((i-j+1)-maxfreq >k)
            {
                ans[s[j]-'A']--;
                maxfreq=0;
                for(int k=0 ; k< 26 ; k++)
                {
                    maxfreq=max(maxfreq, ans[k]);
                }
                j++;
            }
             maxlen=max(maxlen, i-j+1);
        }
        return maxlen;    
    }
};