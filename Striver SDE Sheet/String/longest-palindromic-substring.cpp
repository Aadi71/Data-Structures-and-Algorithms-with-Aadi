// https://leetcode.com/problems/longest-palindromic-substring/

// Gonna Learn Manacher's Algorithm which is the best optimized time complexity of O(N) algorithm to find the longest palindromic substring.

// TC: O(n^2), Checking palindromie by taking centres
class Solution {
public:
    int isPalin(string s, int i, int e){
        while(i >= 0 && e < s.size() && s[i] == s[e]) {i--; e++;}
        return e - i - 1;
    }
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int start = 0, end = 0;
        for(int i = 0; i<s.size(); i++){
            int a = isPalin(s, i, i);
            int b = isPalin(s, i, i + 1);
            int c = max(a, b);
            if(c > end - start){
                start = i - (c - 1) / 2;
                end = i + c / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// Brute Force: Time Limit Exceeded, TC: O(N^3) Solution
class Solution {
public:
    bool isPalindromie(string s, int start, int end){
        while(start <= end) if(s[start++] != s[end--]) return false;
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                if(isPalindromie(s, i, j)){
                    string temp = s.substr(i, j - i + 1);
                    if(temp.size() > ans.size()) ans = temp;
                }
            }
        }
        return ans;
    }
};
