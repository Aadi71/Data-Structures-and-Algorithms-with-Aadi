// https://leetcode.com/problems/powx-n/

// Brute Force, Time Limit Exceeded. TC: O(N)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        for(int i = 0; i < abs(n); i++) ans = ans * x;
        if(n > 0) return ans;
        return 1 / ans;
    }
};

// Optimized Approach with TC: O(logN)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        while (n) {
            if (n % 2) ans = n > 0 ? ans * x : ans / x;
            x = x * x;
            n /= 2;
        }
        return ans;
    }
};

