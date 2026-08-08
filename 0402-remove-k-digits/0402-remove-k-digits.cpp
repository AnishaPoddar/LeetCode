class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0 ; i< num.size(); i++)
        {
            if(st.empty() || st.top() < num[i])
            {
                st.push(num[i]);
            }
            else
            {
                while(k>0 && !st.empty() && st.top() > num[i])
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        while(k > 0 && !st.empty()) {
             st.pop();
            k--;
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(char(st.top()));
            st.pop();
        }
        while(!ans.empty() && ans[ans.size()-1]=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty())
            return "0";
        return ans;
        
    }
};