// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for(auto x: magazine){
            count[x - 'a']++;
        }
        for(auto x: ransomNote){
            if(count[x - 'a'] > 0) count[x - 'a']--;
            else return false;
        }
        return true;
    }
};
