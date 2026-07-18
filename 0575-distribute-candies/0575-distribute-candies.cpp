class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int , int> mp;
        for(int i=0 ; i< candyType.size(); i++)
        {
            mp[candyType[i]]++;
        }
        int can_eat=candyType.size()/2;
        if (can_eat> mp.size())
        {
            return mp.size();
        }
        return can_eat;

    }
};