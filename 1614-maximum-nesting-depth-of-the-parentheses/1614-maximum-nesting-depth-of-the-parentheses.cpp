class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count=0;
        int total_count=0;
        for(int i=0 ;i< s.size(); i++)
        {
            if(s[i]=='(')
            { 
                 count+=1;
                 total_count=max(total_count,count);
            }
            else if( s[i]==')')
            {
                count-=1;
            }

        }
        return total_count;
    }
};