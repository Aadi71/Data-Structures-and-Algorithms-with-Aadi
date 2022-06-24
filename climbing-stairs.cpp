// https://leetcode.com/problems/climbing-stairs/


// Basically, it's a fibonacci series and we just have to return the sum of last two numbers


class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int a = 1;
        int b = 2;
        int sum = 0;
        
        for(int i = 3; i<=n; i++){
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
};
