class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        stack<string> st2;
        string ans;
        string temp="";
        int num=0;
        for(int i=0 ; i< s.size(); i++)
        {
            if(s[i]>='0'&& s[i]<='9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if( s[i]=='[')
            {
                st.push(num);
                st2.push(temp);
                num=0;
                temp="";
            }
            else if(s[i]>='a'&&s[i]<='z')
            {
                temp.push_back(s[i]);
            }
            else
            {
                int k=st.top();
                st.pop();
                string prev=st2.top();
                st2.pop();
                for(int i=1; i<=k ; i++)
                {
                    prev+=temp;
                }
                temp=prev;
            }
        } 
        return temp;
    }
};