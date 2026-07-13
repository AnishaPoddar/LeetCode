class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> output;
        int l1=0;
        int l2=0;
        int start=low;
        int end=high;
        while(start>0)
        {
            l1=l1+1;
            start=start/10;
        }
        while(end>0)
        {
            l2=l2+1;
            end=end/10;
        }
        
        for(int i=l1; i<=min(l2, 9); i++)
        {
            int starting_digit=1;
            while(starting_digit!=-1)
            {
                int num=0;
            for(int j=0; j<i ; j++)
            {
                num=num*10+(starting_digit+j);
                if(starting_digit+j==9)
                {
                    starting_digit=-2;
                    break;
                }

            }
            starting_digit+=1;
            if(num>=low && num<=high)
            {
                output.push_back(num);
            }

            }
        }
        return output;
        
    }
};