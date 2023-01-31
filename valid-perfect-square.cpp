// https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int min = 1;
        int max = num / 2;
        while(min <= max){
            long long int mid = min + (max - min) / 2;
            if(mid * mid == num) return true;
            else if(mid * mid < num) min = mid + 1;
            else max = mid -1;
        }
        return false;
    }
};
