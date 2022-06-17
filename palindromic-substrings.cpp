// https://leetcode.com/problems/palindromic-substrings/


class Solution {
public:
    int countSubstrings(string s) {
        int sum = 0;
        
        for(int i = 0; i<s.length(); i++){
            // for Odd palindromes
            int j = i;
            int k = i;
            while(j >= 0 && k<s.length() && s[j] == s[k]){
                sum++;
                j--;
                k++;
            }
            
            // for Even palindromes
            j = i;
            k = i+1;
            while(j >= 0 && k<s.length() && s[j] == s[k]){
                sum++;
                j--;
                k++;
            }
        }
        return sum;
    }
};
