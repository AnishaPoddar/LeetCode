class Solution {
public:
    bool prime(int n)
    {
        if(n<2 )
        {
            return false;
        }
        if(n == 2)
        return true;

        if(n % 2 == 0)
        return false;

        for(int i=2 ; i*i<=n ; i++)
        {
            if(n % i == 0)
            return false;
        }
        return true;
    }
    int primePalindrome(int n) {
         //all even length palindrone numbers are divisible by 11
    if(n>=8 && n <=11)
         {
            return 11;
         }  
      for(int i=1; i<100000 ; i++)
    {
        string s=to_string(i);
        string rev=s;
        reverse(rev.begin(), rev.end());
        rev.erase(rev.begin());
        int num=stoi(s+rev);
        if(num>=n && prime(num))
        {
            return num;
        }
}
      return -1;
}      
};