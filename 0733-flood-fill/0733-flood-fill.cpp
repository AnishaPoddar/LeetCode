class Solution {
public:
    void bfs(vector<vector<int>>& image , int sr , int sc ,int color,vector<vector<int>>&visited)
    {
        int rows=image.size();
        int cols=image[0].size();

        visited[sr][sc] = 1;

        queue<pair<int, int>> q;
        q.push({sr,sc});
        int temp=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;

                if(row -1 >=0)
                {
                    if(image[row-1][col]==temp && visited[row-1][col]!=1)
                    {
                        q.push({row-1, col});
                        visited[row-1][col]=1;
                        image[row-1][col]=color;
                    }

                }
                if ( row +1 < rows)
                {
                    if(image[row+1][col]==temp && visited[row+1][col]!=1)
                    {
                        q.push({row+1, col});
                        visited[row+1][col]=1;
                        image[row+1][col]=color;
                    }
                }
                if( col -1 >= 0)
                {
                    if(image[row][col-1]==temp && visited[row][col-1]!=1)
                    {
                        q.push({row, col-1});
                        visited[row][col-1]=1;
                        image[row][col-1]=color;
                    }

                }
                if(col +1 < cols)
                {
                    if(image[row][col+1]==temp && visited[row][col+1]!=1)
                    {
                        q.push({row, col+1});
                        visited[row][col+1]=1;
                        image[row][col+1]=color;
                    }

                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(), vector<int> (image[0].size(),0));
        bfs(image , sr , sc , color, visited);
        return image;    
    }
};