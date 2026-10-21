class Solution {
public:
    int minOperations(string s) {
        string s1=s;
        sort(s1.begin(),s1.end());
        if(s1==s)
        {
            return 0;
        }
        if(s.size()==2 && s1!=s)
        {
            return -1;
        }
        int min_asc=s[0];
        int max_asc=s[0];
        for(int i=1 ; i< s.size(); i++)
        {
            min_asc=min(min_asc, int(s[i]));
            max_asc=max(max_asc ,int( s[i])); 
        }
        if(int(s[0])==min_asc || int(s[s.size()-1])==max_asc)
        {
            return 1;
        }
        if(s.find(min_asc) == s.size() - 1 && s.rfind(max_asc) == 0)
        {
            return 3;
        }
        return 2;
    }
};