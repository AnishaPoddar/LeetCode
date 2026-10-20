class Solution {
public:
void bfs(vector<vector<int>>& grid , vector<vector<int>>& visited,queue<pair<int,int>> q, vector<vector<int>>& ans)
    {
        
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
            if (visited[row-1][col] != 1)
                {
                    visited[row-1][col] = 1;
                    ans[row-1][col] = ans[row][col] + 1;
                    q.push({row-1, col});
                }
        }
        if( row < rows-1)
        {
            if (visited[row+1][col] != 1)
                {
                    visited[row+1][col] = 1;
                    ans[row+1][col] = ans[row][col] + 1;
                    q.push({row+1, col});
                }
        }
        if(col>0)
        {
           if (visited[row][col-1] != 1)
           {
                visited[row][col-1] = 1;
                ans[row][col-1] = ans[row][col] + 1;
                q.push({row, col-1});
            }
        }
        if( col < cols-1)
        {
           if (visited[row][col+1] != 1)
            {
                visited[row][col+1] = 1;
                ans[row][col+1] = ans[row][col] + 1;
                q.push({row, col+1});
            }
        }
        }

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int> (mat[0].size()));
        vector<vector<int>> visited(mat.size(), vector<int> (mat[0].size(),0));
        queue<pair<int,int>> q;
        for(int i=0 ; i< mat.size(); i++)
        {
            for(int j=0 ; j< mat[0].size(); j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        bfs(mat, visited, q, ans);
        return ans;
        
    }
};