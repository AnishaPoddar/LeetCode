class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score=0;
        int maxscore=0;
        int j=tokens.size()-1;
        int i=0;
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                score+=1;
                maxscore=max(maxscore, score);
                power-=tokens[i];
                i++;
            }
            else
            {
                if(score>=1)
                {
                    score-=1;
                    power+=tokens[j];
                    j--;
                }
                else
                {
                    break;
                }
            }
        }
        return maxscore;
        
    }
};