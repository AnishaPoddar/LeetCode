class Solution {
public:
bool bfs(vector<vector<int>>& graph , vector<int>& color , int sr)
{
    color[sr]=0;
    queue<int> q;
    q.push(sr);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=0; i< graph[node].size(); i++)
        {
            if(color[graph[node][i]]==-1)
            {
                color[graph[node][i]]=color[node]==0?1:0;
                q.push(graph[node][i]);
            }
            else
            {
                if((color[node]==color[graph[node][i]]))
                {
                    return false;
                }
            }
        }
    }
    return true;


}
bool isBipartite(vector<vector<int>>& graph) {
     vector<int> color(graph.size(),-1);
     for(int i=0; i<graph.size(); i++)
     {
        if(color[i]==-1)
        {
            if(!bfs(graph , color , i))
            {
                return false;
            }
        }
     }
        return true;  
    }
};