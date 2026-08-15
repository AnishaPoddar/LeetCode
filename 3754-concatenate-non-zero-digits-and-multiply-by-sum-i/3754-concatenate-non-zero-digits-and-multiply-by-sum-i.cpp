class Solution {
public:
    long long sumAndMultiply(int n){
        long long temp=0;
        long long temp2=0;
        long long sum=0;
        while(n>0)
        {
            int r=n%10;
            if(r!=0)
            {
                temp=temp*10+r;
            }
            sum=sum+r;
            n=n/10;
        }
        while (temp>0)
        {
            temp2=temp2*10 +(temp%10);
            temp=temp/10;
        }
        return temp2*sum;
    }
};