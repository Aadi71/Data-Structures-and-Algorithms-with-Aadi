// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> occurence(26, 0);
        for(int  i = 0; i<s.length(); i++) occurence[s[i] - 97]++;
        for(int i = 0; i<s.length(); i++) if (occurence[s[i] - 97] == 1) return i; 
        return -1;
    }
};
