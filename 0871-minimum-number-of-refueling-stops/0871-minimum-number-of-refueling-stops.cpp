class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int count=0;
        priority_queue<int , vector<int> > maxheap;
        int k=0;
        while(startFuel < target)
        {
            while(k< stations.size() && startFuel>= stations[k][0])
            {
                maxheap.push(stations[k][1]);
                k++;
            }
            if(maxheap.empty())
            {
                return -1;
            }
            count++;
            startFuel+=maxheap.top();
            maxheap.pop();
        }
        return count;
        
    }
};