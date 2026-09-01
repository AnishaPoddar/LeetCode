class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int i=0;
        int j=people.size()-1;
        int boatcount=0;
        while(i<=j)
        {
            if(i+1<=j && people[i]+people[i+1]<=limit)
            {
                boatcount++;
                i+=2;
            }
            else if(people[i]+people[j]<=limit)
            {
                boatcount++;
                i++;
                j--;
            }
            else
            {
                boatcount++;
                i++;
            }
        }
       return boatcount; 
    }
};