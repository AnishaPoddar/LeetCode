class Solution {
public:
    int bfs( vector<vector<int>>& visited , queue<pair<int,int>>& q, vector<vector<int>>& grid)
    {
        int rows=grid.size();
        int cols=grid[0].size();
    
        int level=-1;
        int d_row[]={-1, 0, 0 , 1};
        int d_col[]={0, -1 , 1 , 0};
        while(!q.empty())
        {
            int sz=q.size();
            level+=1;
            for(int i=0; i< sz; i++)
        {
            pair<int,int> node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second; 
            for(int i=0 ; i<4 ; i++)
            {
                if(row+ d_row[i]>=0 && row + d_row[i]< rows && col + d_col[i]>=0 && col+ d_col[i]< cols)
                {
                    if(visited[row+ d_row[i]][col+d_col[i]]!=1)
                    {
                        visited[row+d_row[i]][col + d_col[i]]=1;
                        q.push({row+d_row[i], col+d_col[i]});
                    }
                }
            }
        }
        }
        return level;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size()));
        for(int i=0; i< grid.size(); i++)
        {
            for(int j=0; j< grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        if (q.empty() || q.size() == grid.size() * grid[0].size()) return -1;
        return bfs(visited, q, grid);
    }
};