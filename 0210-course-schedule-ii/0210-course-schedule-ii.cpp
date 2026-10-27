class Solution {
public:
bool dfs(vector<vector<int>>& adj, vector<int>& visited , int node , stack<int>& s)
{
    visited[node]=1;
    for(int i=0 ; i<adj[node].size(); i++)
    {
        if(visited[adj[node][i]]==1)
        {
            return false;
        }
        if(visited[adj[node][i]]==0)
        {
        if(!dfs(adj , visited , adj[node][i] , s))
        {
            return false;
        }
        }
    }
    visited[node]=2;
    s.push(node);
    return true;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0 ; i< prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        stack<int> s;
        for(int i=0; i< numCourses; i++)
        {
            if(visited[i]==0)
            {
                if(!dfs(adj , visited , i, s))
                {
                    return {};
                }
            }
        }vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};