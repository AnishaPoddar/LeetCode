class Solution {
public:
    bool bfs(vector<vector<int>>& graph , vector<int>& colour, int sr)
    {
        queue<int> q;
        q.push(sr);
        colour[sr]=0;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            int col=colour[node];
            for(int i=0 ; i< graph[node].size(); i++)
            {
                if(colour[graph[node][i]]==-1)
                {
                    colour[graph[node][i]]=(col==1)?0:1;
                    q.push(graph[node][i]);
                }
                else if(colour[graph[node][i]]==col)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(),-1);
        for(int i=0; i< graph.size(); i++)
        {
            if(colour[i]==-1)
            {
                if(bfs(graph , colour, i)==false)
                {
                    return false;
                }
            }
        }
        return true;   
    }
};