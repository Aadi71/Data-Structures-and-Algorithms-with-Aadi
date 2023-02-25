// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, b = 0, sign = 1;
        while(s[i] == ' ') i++;
        if(s[i] == '-' || s[i] == '+') sign = 1 - 2 * (s[i++] == '-');
        while(s[i] >= '0' && s[i] <= '9'){
            if(b > INT_MAX / 10 || (b == INT_MAX / 10 && s[i] - '0' > 7)){
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            b = b * 10 + (s[i++] - '0');
        }
        return b * sign;
    }
};
