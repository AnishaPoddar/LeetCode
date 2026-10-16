class Solution {
public:
   void bfs(vector<vector<char>>& grid , vector<vector<int>>& visited, int start1, int start2)
   {
    queue<pair<int,int>> q;
    q.push({start1, start2});
    visited[start1][start2]=1;

    int rows = grid.size();
    int cols = grid[0].size();

    while(!q.empty())
    {
        pair<int,int> node=q.front();
        q.pop();
        int row = node.first;
        int col = node.second;
        for(int i=0; i< 4 ; i++)
        {
            if( row -1 >=0)
            {
                if (grid[row - 1][col] == '1' && visited[row - 1][col] != 1) {
                    visited[row - 1][col] = 1;
                    q.push({row - 1, col});
                }

            }
            if ( row +1< rows)
            {
                if (grid[row + 1][col] == '1' && visited[row + 1][col] != 1) {
                    visited[row + 1][col] = 1;
                    q.push({row + 1, col});
                }
            }
            if( col -1 >=0)
            {
                if (grid[row][col - 1] == '1' && visited[row][col - 1] != 1) {
                    visited[row][col - 1] = 1;
                    q.push({row, col - 1});
                }

            }
            if(col +1 < cols)
            {
                if (grid[row][col + 1] == '1' && visited[row][col + 1] != 1) {
                    visited[row][col + 1] = 1;
                    q.push({row, col + 1});
                }
            }
        }
        
    }
   }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size(), 0));
        int count=0;
        for(int i=0 ; i< grid.size(); i++)
        {
            for(int j=0 ; j< grid[i].size(); j++)
            {
            if(grid[i][j]=='1' && visited[i][j]!=1)
            {
                count++;
                bfs(grid, visited , i, j);
            }
            }
        }
        return count;   
    }
};