// https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        vector<int> f1(26, 0), v1(26, 0), f2(26, 0), v2(26, 0);
        for(int i = 0; i<word1.length(); i++){
            f1[word1[i] - 'a']++; f2[word2[i] - 'a']++;
            v1[word1[i] - 'a'] = 1; v2[word2[i] - 'a'] = 1;
        } 
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2 && v1 == v2;
    }
};
