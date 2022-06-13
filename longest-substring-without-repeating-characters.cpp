// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int n = s.length();
        int start = -1;
        int maxlen = 0;
        int i = 0;
        while(i < n){
            if(v[s[i]] > start) start = v[s[i]];
            v[s[i]] = i;
            maxlen = max(maxlen, i - start);
            i++;
        }
        return maxlen;
    }
};
