class Solution {
public:
    bool canAliceWin(int n) {
        int a=10;
        while(n>=0)
        {
            n-=a--;
            if(n<0)
            {
                return false;
            }
            n-=a--;
            if(n < 0)
            {
                return true;
            }
        }
        return true;
    }
};