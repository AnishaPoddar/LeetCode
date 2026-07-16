class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s="balloon";
        unordered_map<char, int> mp={{'b',1}, {'a',1}, {'l',2}, {'o', 2}, {'n',1}};
        unordered_map<char, int> mp2;
        for(int i=0 ; i<text.size(); i++)
        {
            if(mp.find(text[i])!=mp.end())
            {
                mp2[text[i]]++;
            }   
        }
        int ans=INT_MAX;
        for(int i=0 ; i<s.size(); i++)
        {
            if(mp2.find(s[i])==mp2.end() )
            {
                return 0;
            }
            ans=min(ans,mp2[s[i]] / mp[s[i]]);
        }
        return ans; 
    }
};