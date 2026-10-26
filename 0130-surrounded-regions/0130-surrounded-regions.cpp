class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        vector<vector<int>> visited(board.size(), vector<int> (board[0].size(), 0));
        queue<pair<int,int>> q;
        for(int i=0 ; i< board.size(); i++)
        {
            for(int j=0; j< board[0].size(); j++)
            {
                if(i==0|| i==board.size()-1 || j==0|| j==board[0].size()-1)
                {
                    if(board[i][j]=='O')
                    {
                        q.push({i,j});
                        visited[i][j]=1;
                    }

                }
            }
        }
        
        
        int rows=board.size();
        int cols=board[0].size();

        while(!q.empty())
        {
        pair<int,int> node=q.front();
        q.pop();
        int row=node.first;
        int col=node.second;

        if(row>0)
        {
            if(board[row-1][col]=='O' && visited[row-1][col]!=1 )
            {
                q.push({row-1,col});
                visited[row-1][col]=1;
            }
        }
        if( row < rows-1)
        {
            if(board[row+1][col]=='O' && visited[row+1][col]!=1)
            {
                q.push({row+1, col});
                visited[row+1][col]=1;
            }
        }
        if(col>0)
        {
            if(board[row][col-1]=='O' && visited[row][col-1]!=1)
            {
                q.push({row,col-1});
                visited[row][col-1]=1;
            }
        }
        if( col < cols-1)
        {
            if(board[row][col+1]=='O' && visited[row][col+1]!=1)
            {
                q.push({row, col+1});
                visited[row][col+1]=1;
            }
        }
        }
        for(int i=1 ; i< rows-1 ; i++)
        {
            for(int j=1; j< cols-1; j++)
            {
                if(board[i][j]=='O' && visited[i][j]!=1)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};