class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int len=0;
        vector<int> freq(26,0);
        for(int j=0 ; j < s.size(); j++)
        {
            freq[s[j]-'a']++;
            while(freq[s[j]-'a'] > 2)
            {
                freq[s[i]-'a']--;
                i++;
            }

            len=max(len, j-i+1);
        }
    return len;
    }
};