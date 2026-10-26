class Solution {
public:
bool bfs(vector<vector<int>>& grid , vector<vector<int>>& visited , int sr , int sc)
{
    bool closed=true;
    int rows=grid.size();
    int cols=grid[0].size();

    queue<pair<int,int>> q;
    q.push({sr, sc});
    visited[sr][sc]=1;
    while(!q.empty())
    {
        pair<int,int> node=q.front();
        q.pop();
        int row=node.first;
        int col=node.second;

        if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
                closed = false;
            }

        if(row>0)
        {
            if(grid[row-1][col]==0 && visited[row-1][col]!=1)
            {
                q.push({row-1, col});
                visited[row-1][col]=1;
            }
        }
        if(row < rows-1)
        {
            if(grid[row+1][col]==0 && visited[row+1][col]!=1)
            {
                q.push({row+1, col});
                visited[row+1][col]=1;
            }
        }
        if( col> 0)
        {
            if(grid[row][col-1]==0 && visited[row][col-1]!=1)
            {
                q.push({row , col-1});
                visited[row][col-1]=1;
            }
        }
        if( col< cols-1)
        {
            if( grid[row][col+1]==0 && visited[row][col+1]!=1)
            {
                q.push({row , col+1});
                visited[row][col+1]=1;
            }
        }
        
    }
    return closed;
}
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(),0));
        int count=0;
        for(int i=0 ; i< grid.size() ; i++)
        {
            for(int j=0 ; j< grid[0].size(); j++)
            {
                if(grid[i][j]==0 && visited[i][j]!=1)
                {
                    if(bfs(grid , visited , i , j))
                    {
                        count+=1;
                    }
                }
            }
        }
        return count;   
    }
};