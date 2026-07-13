class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()!=2)
        {
            for(int i=0 ; i<s.size()-1; i++)
            {
                int sum = (s[i] - '0') + (s[i + 1] - '0');
                s[i] = (sum % 10) + '0';
            }
            s.pop_back();
        }
        return s[0]==s[1];
        
    }
};