// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> v1(256, 0);
        vector<int> v2(256, 0);
        
        for (int i = 0; i < s.size(); ++i) {
            if (v1[s[i]] != v2[t[i]]) return false;
            v1[s[i]] = i + 1;
            v2[t[i]] = i + 1;
        }
        return true;
    }
};
