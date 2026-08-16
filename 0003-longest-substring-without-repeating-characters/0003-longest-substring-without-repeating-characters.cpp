class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256);
        int j=0;
        int i=0;
        int ans=0;
        for(i=0 ; i< s.size(); i++)
        {
            freq[int(s[i])]++;
            while(freq[int(s[i])]>1)
            {
                freq[int(s[j])]--;
                j++;
            }
            ans=max(ans, i-j+1);
        }
        return ans;   
    }
};