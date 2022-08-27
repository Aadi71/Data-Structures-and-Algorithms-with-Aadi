// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length() - 1;
        int lenb = b.length() - 1;
        string result;
        int carry = 0;
        int sum = 0;
        while(lena >= 0 || lenb >= 0){
            sum = 0;
            sum += lena >= 0 ? a[lena --] - '0' : 0;
            sum += lenb >= 0 ? b[lenb --] - '0' : 0;
            sum += carry;
            if(carry > 0) carry--;
            if(sum == 0) result.insert(0, "0"); 
            else if(sum == 1) result.insert(0, "1"); 
            else if(sum % 2 == 0){
                result.insert(0, "0"); 
                carry += sum / 2;
            }
            else{
                result.insert(0, "1"); 
                carry += sum / 2;
            }
        }
        while(carry > 0){
            result.insert(0, "1");
            carry--;
        }
        return result;
    }
};
