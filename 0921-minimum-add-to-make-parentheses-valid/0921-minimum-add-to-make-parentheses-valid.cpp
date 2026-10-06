class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count=0;
        int unclose_count=0;
        for(int i=0 ; i< s.size() ; i++)
        {
            if(s[i]=='(')
            {
                open_count++;
            }
            else
            {
                if(open_count<=0)
                {
                    unclose_count++;
                }
                else
                {
                    open_count--;
                }
            }
        }
        return open_count + unclose_count;
        
    }
};