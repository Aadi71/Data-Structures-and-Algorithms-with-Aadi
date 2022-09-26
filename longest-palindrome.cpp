// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(52, 0);
        for(char i: s){
            if(i >= 'a') v[i - 'a']++;
            else v[i - 'A' + 26]++;
        }
        int even = 0, odd = 0; 
        for(int i = 0; i<52; i++){
            even += v[i] - v[i] % 2;
            v[i] = v[i] % 2; 
            if(v[i] % 2 != 0) odd = 1;
        }
        return odd + even;
    }
};
