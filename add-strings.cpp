// https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int a = num1.length() - 1;
        int b = num2.length() - 1;
        int sum = 0;
        int carry = 0;
        string result = "";
        while(a >= 0 || b >= 0){
            sum = 0;
            sum += carry;
            carry = 0; 
            sum += a >= 0 ? num1[a--] - '0' : 0;
            sum += b >= 0 ? num2[b--] - '0' : 0;
            carry += sum / 10;
            result.insert(0, to_string(sum % 10));
        }
        if(carry != 0) result.insert(0, to_string(carry));                          
        return result;
        
    }
};
