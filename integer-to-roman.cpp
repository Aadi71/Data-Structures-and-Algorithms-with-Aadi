// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    
    
    string intToRoman(int num) {
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string f;
        int i = 0;
        while(num){
            while(val[i] <= num){
                f += rom[i];
                num -= val[i];
            }
            i++;
        }
        return f;
    }
};
