class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s="";
        for(int i=0 ; i< n ; i++)
        {
            s.push_back('.');
        }
        ans.push_back(s);
        for(int i=1 ; i< m ; i++)
        {
            s="";
            for(int j=0; j< n ; j++)
            {
                if(j==n-1)
                {
                    s.push_back('.');
                }
                else
                {
                    s.push_back('#');
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};