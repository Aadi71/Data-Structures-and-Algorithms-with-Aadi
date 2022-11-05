// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution {
public:
    int countSetBits(int n){
        int c = 0;
        while(n){
            n &= (n - 1);
            c += 1;
        }
        return c;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++){
            int p = countSetBits(i);
            if(p == 2 || p == 3 || p == 5 || p == 7 || p == 11 || p == 13 || p == 17 || p == 19) ans++;
        }
        return ans;
    }
};
