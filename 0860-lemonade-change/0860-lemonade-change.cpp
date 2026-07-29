class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count=0;
        int count2=0;
        if(bills[0]!=5)
        {
            return false;
        }
        for(int i=0; i< bills.size(); i++)
        {
            if(bills[i]==5)
            {
                count+=1;
            }
            else if(bills[i]==10)
            {
                if(count==0)
                {
                    return false;
                }
                count-=1;
                count2+=1;
            }
            else
            {
                if(count2>0 && count>0) 
                {
                    count-=1;
                    count2-=1;
                }
                else if(count>=3)
                {
                    count-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};