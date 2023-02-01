// https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if(a + b != b + a) return "";
        return a.substr(0, gcd(a.size(), b.size()));
    }
};
