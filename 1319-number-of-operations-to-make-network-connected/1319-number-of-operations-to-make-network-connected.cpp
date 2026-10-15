class Solution {
public:
void bfs(int start ,vector<vector<int>>& isConnected , vector<int>& visited)
    {
        queue<int> q;
        q.push(start);
        visited[start]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0; i< isConnected[node].size(); i++)
            {
                if(!visited[isConnected[node][i]])
            {
                q.push(isConnected[node][i]);
                visited[isConnected[node][i]] = 1;
            }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()< n-1)
        {
            return -1;
        }
        vector<vector<int>> adj(n);
        for(int i=0 ; i< connections.size(); i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        int count=0;
        for(int i=0; i< n; i++)
        {
            if(visited[i]==0)
            {
                count++;
                bfs(i, adj , visited);
            }
        }
        return count-1;   
    }
};