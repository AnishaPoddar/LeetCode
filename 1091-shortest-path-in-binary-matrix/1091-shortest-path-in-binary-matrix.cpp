class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& level )
    {
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0]=1;
        level[0][0]=1;

        int rows=grid.size();
        int cols=grid[0].size();

        int dr[]={-1, -1 , -1 , 0 , 0 , 1 , 1 ,1 };
        int dc[]={-1, 0 , 1 , -1 , 1, -1 , 0, 1 };
        
        while(!q.empty())
        {
        pair<int,int> node=q.front();
        q.pop();

        for(int i=0 ;i< 8 ; i++)
        {
            int row=node.first+ dr[i];
            int col=node.second + dc[i];
            if( row>=0 && row<=rows-1 && col>=0 && col<=cols-1 && grid[row][col]==0 )
            {
                grid[row][col]=1;
                level[row][col]=level[node.first][node.second]+1;
                q.push({row, col});
            }
        }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> level(grid.size(), vector<int> (grid[0].size(),-1));
        if(grid[0][0]==1 || grid[grid.size()-1][grid.size()-1]==1  )
        {
            return -1;
        }
        bfs(grid, level );
        return level[grid.size()-1][grid.size()-1]; 
    }
};