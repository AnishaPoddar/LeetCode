class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int count=0;
        int j=0;
        for(int i=0 ; i< s.size(); i++)
        {
            freq[s[i]-'a']++;
            while(freq[0]>= 1 && freq[1]>=1 && freq[2]>=1)
            {
                count+=s.size()-i;
                freq[s[j]-'a']--;
                j++;
            }

        } 
        return count;
    }
};