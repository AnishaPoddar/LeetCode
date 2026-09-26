class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int index=INT_MIN;
        string ans="";
        unordered_map<string , string> mp(knowledge.size());
        for(int i=0 ; i< knowledge.size(); i++)
        {
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0 ;i< s.size() ; i++)
        {
            if(s[i]=='(')
            {
                index=i;
            }
            else if(s[i]==')')
            {
                string temp=s.substr(index+1, i-index-1);
                if(mp.find(temp)!=mp.end())
                {
                    ans.append(mp[temp]);
                }
                else
                {
                    ans.push_back('?');
                }
                index=INT_MIN;
            }
            else if(index==INT_MIN)
            {
                ans.push_back(s[i]);
            }

        }
        return ans;
        
    }
};