//https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0)
            return !(n & (n-1));
        else 
            return 0;
    }
};
