class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(256,0);
        string ans;
        if(s.size()==1)
        {
            return s;
        }
        for(int i=0 ; i<s.size(); i++)
        {
            arr[s[i]]++;
        }
        for(int i=0 ;i < 256; i++)
        {
           if(arr[i]!=0)
           {
             ans.append(floor(arr[i]/2), char(i));
            arr[i]=arr[i]%2;
           }
        }
        string rev=ans;
        reverse(rev.begin(), rev.end());
        for(int i=0 ; i< 256; i++)
        {
           if(arr[i]!=0)
           {
            ans.append(arr[i], char(i));
           }
        }
        return ans+rev;
    }
};