class Solution {
public:
    void bfs(vector<vector<int>>& rooms , vector<int>& visited)
    {
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0 ;i < rooms[node].size(); i++)
            {
                if(visited[rooms[node][i]]==0)
                {
                    q.push(rooms[node][i]);
                    visited[rooms[node][i]]=1;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size());
        bfs(rooms, visited);
        for(int i=0 ; i< rooms.size(); i++)
        {
            if(visited[i]==0)
            {
                return false;
            }
        }
        return true; 
    }
};