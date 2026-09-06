class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineers(n);
        for(int i=0; i< n ; i++)
        {
            engineers[i].first=speed[i];
            engineers[i].second=efficiency[i];
        }
        sort(engineers.begin(), engineers.end(),[](const pair<int,int>&x , const pair<int,int>&y){
            return x.second>y.second; 
        });
        priority_queue<int, vector<int> , greater<int>> minheap;
        long long sumspeed=0;
        long long performance=0;
        long long maxperformance=0;
        for(int i=0; i< n ; i++)
        {
            if(i+1<=k)
            {
                sumspeed+=engineers[i].first;
                performance=sumspeed*engineers[i].second;
                maxperformance=max(performance, maxperformance);
                minheap.push(engineers[i].first);
            }
            else
            {
                sumspeed+=engineers[i].first;
                sumspeed-=minheap.top();
                minheap.pop();
                performance=sumspeed*engineers[i].second;
                maxperformance=max(performance, maxperformance);
                minheap.push(engineers[i].first);
            }  
        }
        return maxperformance%(1000000007);
    
    }
};