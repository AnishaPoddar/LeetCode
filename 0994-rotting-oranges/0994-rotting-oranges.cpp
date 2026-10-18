class Solution {
public:
    int bfs(vector<vector<int>>& grid ,vector<vector<int>>& visited)
    {
        queue<pair<int,int>> q;
        
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        
        int time=0;
        while(!q.empty())
        {
        int sz = q.size();
        bool added=false;
        for(int k = 0; k < sz; k++) {
        pair<int,int> node=q.front();
        q.pop();
        int row = node.first;
        int col = node.second;
        
            if( row -1 >=0)
            {
                if ((grid[row - 1][col] == 1 || grid[row - 1][col] == 2) && visited[row - 1][col] != 1) {
                    q.push({row - 1, col});
                    visited[row-1][col]=1;
                    added=true;
                }

            }
            if ( row +1< rows)
            {
                if ((grid[row + 1][col] == 1|| grid[row + 1][col] == 2) && visited[row + 1][col] != 1) {
                    q.push({row + 1, col});
                    visited[row + 1][col] = 1;
                    added=true;
                }
            }
            if( col -1 >=0)
            {
                if ((grid[row][col - 1] == 1||grid[row][col - 1] == 2)  && visited[row][col - 1] != 1) {
                    q.push({row, col - 1});
                    visited[row][col - 1] = 1;
                    added=true;
                }

            }
            if(col +1 < cols)
            {
                if ((grid[row][col + 1] == 1|| grid[row][col + 1] == 2) && visited[row][col + 1] != 1) {
                    q.push({row, col + 1});
                    visited[row][col + 1] = 1;
                    added=true;
                } 
            }
        }
            if(added)
        {
            time+=1;
        }
        }
        
        return time;
    }

    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(),0));
        int min_time = bfs(grid, visited);
        for(int i=0 ; i< grid.size(); i++)
        {
            for(int j=0 ; j< grid[0].size(); j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return min_time;    
    }
};