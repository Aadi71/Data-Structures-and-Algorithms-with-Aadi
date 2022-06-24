// https://leetcode.com/problems/happy-number/


class Solution {
public:
    int square(int n){
        int sum = 0;
        int re;
        while(n > 0){
            re = n % 10;
            sum += re * re;
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        
        int slow = n;
        int fast = n;
        
        do{
            slow = square(slow);
            fast = square(fast);
            fast = square(fast);
            if(fast == 1) return true;
        }while(slow != fast);
        return false;
    }
};
