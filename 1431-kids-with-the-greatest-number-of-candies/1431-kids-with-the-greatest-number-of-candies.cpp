class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=0;
        for(int i=0 ; i<candies.size(); i++)
        {
            if(candies[i]>maxi)
            {
                maxi=candies[i];
            }
        }
        vector<bool> output;
        for(int i=0 ; i<candies.size();i++)
        {
           output.push_back(candies[i]+extraCandies >=maxi);
        }
        return output;
        
    }
};