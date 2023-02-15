// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n - 1;
        int carry = 0;
        while(i >= 0 || carry > 0 || k > 0){
            int sum = carry + (i >= 0 ? num[i] : 0) + k % 10;
            if(i >= 0) num[i] = sum % 10;
            else num.insert(num.begin(), sum % 10);
            carry = sum / 10;
            k = k / 10;
            i--;
        }
        return num;
    }
};
