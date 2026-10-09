class Solution {
public:
    int minInsertions(string s) {
        int open_count=0;
        int closed_count=0;
        int insertion=0;
        for(int i=0; i< s.size(); i++)
        {
            if(s[i]=='(')
            {
                 if(closed_count==1)
                {
                    insertion++;
                    closed_count=0;
                    if(open_count>0) open_count--;
                    else insertion++;            
                }
                open_count++;
            }
            else 
            {
                closed_count++;
                if(closed_count==2)
                {
                    if(open_count<= 0)
                    {
                        insertion++;
                        closed_count-=2;
                    }
                    else
                    {
                    closed_count-=2;
                    open_count-=1;
                    }
                }
                
            }
        }
        if(closed_count!=0)
        {
            if(open_count>0)
            {
                insertion++;
                open_count--;
                closed_count-=1;
            }
            else
            {
                insertion+=2;
            }
        }
        insertion+=open_count*2;
        return insertion;
        
    }
};