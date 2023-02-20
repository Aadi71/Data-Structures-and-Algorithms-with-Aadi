// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> umap;
        for(int i = 0; i<s.length(); i++){
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for(auto it: umap) if(it.second) return false;
        return true;

    }
};
