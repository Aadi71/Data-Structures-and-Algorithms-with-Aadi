// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int v1 = 0;
        for(int i = 0; i<n/2; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') v1++;
        }
        for(int i = n/2; i<n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') v1--;
        }
        if(v1 == 0) return true;
        return false;
    }
};
