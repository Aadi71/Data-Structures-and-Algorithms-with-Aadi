// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;
        string res = "";
        for(int i = 0; i<n; i++){
            int step = 2 * (n - 1);
            for(int j = i; j<s.length(); j+=step){
                res += s[j];
                if(i > 0 && i < n - 1 && j + step - 2 * i < s.length()) res += s[j + step - 2 * i];
            }
        }
        return res;
    }
};
