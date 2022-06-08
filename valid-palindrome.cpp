// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        string final;
        
        for(int i = 0; i<s.length(); i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                if(s[i] >= 'A' && s[i] <= 'Z') final += (s[i] + 32);
                else final += s[i];
            }
        }
        int i = 0, j = final.length() - 1;
        while(i < j){
            if(final[i] != final[j]) return false;
            i++; j--;
        }
        return true;
    }
};
