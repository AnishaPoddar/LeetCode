class Solution {
public:
    void gameOfLife(vector<vector<int>>& boards) {
        int dx[]={-1, -1 , -1 , 0 , 0 , 1 ,1 ,1};
        int dy[]={-1 , 0 , 1 , -1 , 1 , -1 ,0 ,1};
        for(int i=0 ; i< boards.size(); i++)
        {
            for(int j=0 ; j< boards[i].size(); j++)
            {
                int count=0;
                for(int k=0; k< 8 ; k++)
                {
                    int x_index=dx[k]+i;
                    int y_index=dy[k]+j;

                    if(x_index>=0 && x_index< boards.size() && y_index>=0 && y_index <boards[i].size() )
                    {
                        if(boards[x_index][y_index]==1 || boards[x_index][y_index]==2) 
                        {
                            count++;
                        }
                    }
                }
                if( boards[i][j]==1 && count < 2)
                {
                    boards[i][j]=2;
                }
                else if(boards[i][j]==1 && count>3)
                {
                    boards[i][j]=2;
                }
                else if(boards[i][j]==0 && count==3)
                {
                    boards[i][j]=3;
                }

            }
        }
        for(int i=0 ; i< boards.size(); i++)
        {
            for(int j=0 ; j< boards[i].size(); j++)
            {
                if(boards[i][j]==2)
                {
                    boards[i][j]=0;
                }
                else if(boards[i][j]==3)
                {
                    boards[i][j]=1;
                }
            }
        }
        
    }
};