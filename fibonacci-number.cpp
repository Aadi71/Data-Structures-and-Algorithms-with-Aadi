// https://leetcode.com/problems/fibonacci-number/

// Dp Solution
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> arr(n+1, 0);
        arr[0] = 0;
        arr[1] = 1;
        
        for(int i = 2; i<=n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
};


// Recursive Solution
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else return fib(n-1) + fib(n-2);
    }
};
