class Solution {
public:
    int minimumPushes(string word) {
        double count=0;
        for(int i=0 ; i<word.size(); i++)
        {
            count+=ceil(i/8)+1;
        }
        return int(count);
        
    }
};