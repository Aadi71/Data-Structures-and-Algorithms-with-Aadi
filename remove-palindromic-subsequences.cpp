// https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
public:
    bool palindromie(string s){
        int i = 0, j = s.length() - 1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(palindromie(s)) return 1;
        else return 2;
    }
};
