class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int count=0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i=0;
        int j=0;
        for(int i=0 ; i< players.size(); i++)
        {
            while(j < trainers.size() && trainers[j] < players[i]) {
                j++;
            }
            if(j<trainers.size()&& players[i]<=trainers[j])
            {
                j++;
                count++;
            }
        }
        return count;
        
    }
};