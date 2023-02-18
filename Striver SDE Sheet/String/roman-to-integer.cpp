// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        if(s == "") return 0;
        unordered_map<char, int> umap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for(int i = 0; i<s.length() - 1; i++){
            if(umap[s[i]] < umap[s[i + 1]]) sum -= umap[s[i]];
            else sum += umap[s[i]];
        }
        sum += umap[s.back()];
        return sum;
    }
};
