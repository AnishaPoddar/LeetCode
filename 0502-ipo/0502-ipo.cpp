class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> project(profits.size(),vector<int>(2));
        for(int i=0 ;i< profits.size(); i++)
        {
            project[i][0]=profits[i];
            project[i][1]=capital[i];
        }
        sort(project.begin(), project.end(), [](const vector<int>&x , const vector<int>&y)
        {
            return x[1]<y[1];

        });
        priority_queue< int , vector<int>> maxheap;
        int l=0;
        for(int i=0 ; i< project.size(); i++)
        {
            if(project[i][1]<=w)
            {
                maxheap.push(project[i][0]);
            }
            else
            {
                if(l<k)
                {
                if(maxheap.empty()) break; 
                w+=maxheap.top();
                l++;
                maxheap.pop();
                i--;
                }
            }
        }
        while(l<k)
        {
                if(maxheap.empty()) break; 
                w+=maxheap.top();
                maxheap.pop();
                l++;
        }
        return w;
    }
};