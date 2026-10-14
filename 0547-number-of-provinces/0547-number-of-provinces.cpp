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
                if(isConnected[node][i]==1 && visited[i]!=1)
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int count=0;
        for(int i=0; i< isConnected.size(); i++)
        {
            if(visited[i]==0)
            {
                count++;
                bfs(i, isConnected , visited);
            }
        }
        return count;
    }
};