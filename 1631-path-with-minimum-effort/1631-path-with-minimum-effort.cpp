class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dis(heights.size(), vector<int> (heights[0].size(), INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        dis[0][0]=0;
        pq.push({ 0, 0 , 0});

        int rows=heights.size();
        int cols=heights[0].size();

        while(!pq.empty())
        {
            vector<int> node= pq.top();
            int d=node[0];
            int sr=node[1];
            int sc=node[2];
            pq.pop();

            if(sr-1>=0)
            {
                if(max(d , abs(heights[sr][sc]-heights[sr-1][sc]) ) < dis[sr-1][sc])
                {
                    dis[sr-1][sc]=max(d,abs(heights[sr][sc]-heights[sr-1][sc]));
                    pq.push({dis[sr-1][sc], sr-1 , sc});
                }

            }
            if(sr+1 < rows)
            {
                if(max(d , abs(heights[sr][sc]-heights[sr+1][sc] ))< dis[sr+1][sc])
                {
                    dis[sr+1][sc]=max(d , abs(heights[sr][sc]-heights[sr+1][sc]));
                    pq.push({dis[sr+1][sc], sr+1 , sc});
                }
            }
            if(sc-1>=0)
            {
                if(max(d , abs(heights[sr][sc]-heights[sr][sc-1] )) < dis[sr][sc-1])
                {
                    dis[sr][sc-1]=max(d , abs(heights[sr][sc]-heights[sr][sc-1] ));
                    pq.push({dis[sr][sc-1], sr , sc-1});
                }
            }
            if(sc+1< cols)
            {
                if(max(d , abs(heights[sr][sc]-heights[sr][sc+1] ))  < dis[sr][sc+1])
                {
                    dis[sr][sc+1]=max(d , abs(heights[sr][sc]-heights[sr][sc+1] ));
                    pq.push({dis[sr][sc+1], sr , sc+1});
                }
            }
        }
        return dis[rows-1][cols-1];  
    }
};