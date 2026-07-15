class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return ceil(log2(n))==log2(n);
        
    }
};