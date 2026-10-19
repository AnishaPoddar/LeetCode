class Solution {
public:
    void bfs(vector<vector<int>>& grid , vector<vector<int>>& visited, int sr, int sc)
    {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        
        int rows=grid.size();
        int cols=grid[0].size();

        while(!q.empty())
        {
        pair<int,int> node=q.front();
        q.pop();
        int row=node.first;
        int col=node.second;

        if(row>0)
        {
            if(grid[row-1][col]==1 && visited[row-1][col]!=1 )
            {
                q.push({row-1,col});
                visited[row-1][col]=1;
            }
        }
        if( row < rows-1)
        {
            if(grid[row+1][col]==1 && visited[row+1][col]!=1)
            {
                q.push({row+1, col});
                visited[row+1][col]=1;
            }
        }
        if(col>0)
        {
            if(grid[row][col-1]==1 && visited[row][col-1]!=1)
            {
                q.push({row,col-1});
                visited[row][col-1]=1;
            }
        }
        if( col < cols-1)
        {
            if(grid[row][col+1]==1 && visited[row][col+1]!=1)
            {
                q.push({row, col+1});
                visited[row][col+1]=1;
            }
        }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(),0));
        for(int i=0; i< grid[0].size(); i++)
        {
            if(grid[0][i]==1 && visited[0][i]!=1)
            {
                bfs(grid, visited, 0 , i);
            }
        }
        for(int i=0 ; i< grid[0].size(); i++)
        {
            if(grid[grid.size()-1][i]==1 && visited[grid.size()-1][i]!=1)
            {
                bfs(grid, visited, grid.size()-1 , i);
            }
        }
        for(int j=0 ; j< grid.size(); j++)
        {
            if(grid[j][0]==1 && visited[j][0]!=1)
            {
                bfs(grid, visited, j ,0 );
            }
        }
        for(int j=0; j< grid.size(); j++ )
        {
            if(grid[j][grid[0].size()-1]==1 && visited[j][grid[0].size()-1]!=1)
            {
                bfs(grid , visited , j , grid[0].size()-1);
            }
        }
        int count=0;
        for(int i=1 ; i< grid.size()-1 ; i++)
        {
            for(int j=1 ; j< grid[0].size()-1 ; j++)
            {
                if(grid[i][j]==1 && visited[i][j]!=1)
                {
                    count+=1;
                }
            }
        }
        return count; 
    }
};