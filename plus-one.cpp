// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>v;
        int n = digits.size();
        int carry;
        
        digits[n- 1] += 1;
        carry = digits[n - 1] / 10;
        digits[n - 1] = digits[n - 1] % 10;
        v.insert(v.begin(), digits[n - 1]);
        
        for(int i = n - 2; i>=0; i--){
            
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
            
            v.insert(v.begin(), digits[i]);
        }
        while(carry > 0){
            v.insert(v.begin(), carry % 10);
            carry /= 10;
        }
        
        return v;
    }
};
