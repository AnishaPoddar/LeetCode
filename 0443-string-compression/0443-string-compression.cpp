class Solution {
public:
    int compress(vector<char>& chars) {
        char element=chars[0];
        int j=0;
        int count=0;
        for(int i=0 ; i< chars.size(); i++)
        {
            if(chars[i]==element)
            {
                count++;
            }
            else
            {
                chars[j++]=element;
                if(count > 1)
                {
                    string s=to_string(count);
                    for(int i=0; i< s.size(); i++)
                    {
                        chars[j++]=s[i];
                    }
                }
                count=1;
                element=chars[i];
            }
        } 
        chars[j++]=element;
        if(count > 1)
                {
                    string s=to_string(count);
                    for(int i=0; i< s.size(); i++)
                    {
                        chars[j++]=s[i];
                    }
                }
        return j;
    }
};