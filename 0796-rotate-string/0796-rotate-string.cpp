class Solution {
public:
    bool rotateString(string s, string goal) {
        string st=s+s;
        if(s.size()!=goal.length())
        {
            return false;
        }
        if(st.find(goal) != std::string::npos)
        {
            return true;
        }
        return false;   
    }
};