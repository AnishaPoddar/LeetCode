class Solution {
public:
    int bfs(vector<vector<int>>& grid , vector<vector<int>>& visited, int sr , int sc)
    {
        queue<pair<int,int>> q;
        q.push({sr, sc});

        int rows=grid.size();
        int cols=grid[0].size();
        int a=1;
        visited[sr][sc]=a;
        while(!q.empty())
        {
            pair<int, int> node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;

            int dr[]={-1, 0 , 0 , 1};
            int dc[]={ 0, -1 , 1 , 0};

            for(int i=0 ; i<4 ; i++)
            {
                if(row + dr[i] >=0 && row +dr[i]< rows && col + dc[i] >=0 && col + dc[i] < cols)
                {
                    if(grid[row+dr[i]][col+dc[i]]==1 && visited[row+dr[i]][col+dc[i]]==0 )
                    {
                        visited[row+dr[i]][col+dc[i]]=a++;
                        q.push({row+dr[i], col+dc[i]});
                    }
                }
            } 
        }
        return a ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(),0));
        int max_area=0;
        for(int i=0 ; i< grid.size(); i++)
        {
            for(int j=0; j< grid[0].size(); j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    max_area=max(max_area, bfs(grid, visited , i , j));
                }
            }
        }
        return max_area;
    }
};