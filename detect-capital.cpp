// https://leetcode.com/problems/detect-capital/

// Optimized Approach
class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0;
        for(char i: word) if(islower(i)) small++;
        if(small == 0 || (small == word.length() - 1 && isupper(word[0])) || small == word.length()) return true;
        return false;
    }
};

// Brute Force
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int i = 1;
        if(isupper(word[0])){
            while(i < n){
                if(isupper(word[i])) i++;
                else break;
            }
            if(i == n) return true;
            i = 1;
            while(i < n){
                if(islower(word[i])) i++;
                else break;
            }
            if(i == n) return true;
        }
        else{
            while(i < n){
                if(islower(word[i])) i++;
                else break;
            }
            if(i == n) return true;
        }
        return false;
    }
};
