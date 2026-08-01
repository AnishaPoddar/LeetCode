class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i=0 ; i<word.size(); i++)
        {
            freq[word[i]-'a']++;
        }
        sort(freq.begin(), freq.end(),greater<int>());
        int count=0;
        for(int i=0 ; i<freq.size(); i++)
        {
            if(freq[i]==0)
            {
                break;
            }
            if(i<=7)
            {
                count=count+freq[i];
            }
            else if(i<=15)
            {
                count+=2*freq[i];
            }
            else if(i<=23)
            {
                count+=3*freq[i];
            }
            else
            {
                count+=4*freq[i];
            }
        }
        return count;
        
    }
};