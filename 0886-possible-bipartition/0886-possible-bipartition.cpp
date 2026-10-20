class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<int>& group, int sr)
    {
        queue<int> q;
        q.push(sr);
        group[sr]=1;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            int n_group=group[node];

            for(int i=0 ; i< adj[node].size(); i++)
            {
                if(group[adj[node][i]]==0)
                {
                    group[adj[node][i]]=n_group==1?2:1;
                    q.push(adj[node][i]);
                }
                else if(group[adj[node][i]]==n_group)
                {
                    return false;
                }
            }
        }
        return true;

    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0 ;i< dislikes.size(); i++)
        {
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> group(n+1);
        for(int i=1 ; i< group.size(); i++)
        {
            if(group[i]==0)
            {
                if(!bfs(adj , group , i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};