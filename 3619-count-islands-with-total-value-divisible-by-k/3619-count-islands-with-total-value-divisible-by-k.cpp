class Solution {
public:
    bool bfs(vector<vector<int>>& grid , vector<vector<int>>& visited , int sr , int sc, int k)
{
    
    int rows=grid.size();
    int cols=grid[0].size();
    long long sum=0;

    queue<pair<int,int>> q;
    q.push({sr, sc});
    visited[sr][sc]=1;
    sum+=grid[sr][sc];

    while(!q.empty())
    {
        pair<int,int> node=q.front();
        q.pop();
        int row=node.first;
        int col=node.second;

        if(row>0)
        {
            if(grid[row-1][col]!=0 && visited[row-1][col]!=1)
            {
                q.push({row-1, col});
                visited[row-1][col]=1;
                sum+=grid[row-1][col];
            }
        }
        if(row < rows-1)
        {
            if(grid[row+1][col]!=0 && visited[row+1][col]!=1)
            {
                q.push({row+1, col});
                visited[row+1][col]=1;
                sum+=grid[row+1][col];
            }
        }
        if( col> 0)
        {
            if(grid[row][col-1]!=0 && visited[row][col-1]!=1)
            {
                q.push({row , col-1});
                visited[row][col-1]=1;
                sum+=grid[row][col-1];
            }
        }
        if( col< cols-1)
        {
            if( grid[row][col+1]!=0 && visited[row][col+1]!=1)
            {
                q.push({row , col+1});
                visited[row][col+1]=1;
                sum+=grid[row][col+1];
            }
        }
        
    }
    if(sum%k==0)
    {
        return true;
    }
    return false;
}
    int countIslands(vector<vector<int>>& grid, int k) {
         vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(),0));
        int count=0;
        for(int i=0 ; i< grid.size() ; i++)
        {
            for(int j=0 ; j< grid[0].size(); j++)
            {
                if(grid[i][j]!=0 && visited[i][j]!=1)
                {
                    if(bfs(grid , visited , i , j, k))
                    {
                        count+=1;
                    }
                }
            }
        }
        return count;  
        
    }
};