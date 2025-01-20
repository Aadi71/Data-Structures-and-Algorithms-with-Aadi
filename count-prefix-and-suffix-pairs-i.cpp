// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

// TC: O(n^2 * m)
// SC: O(1)

class Solution {
public:
    bool isPrefix(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        if (m > n) return false;
        for (int i = 0; i < m; i++) if (str1[i] != str2[i]) return false;
        return true;
    }
    bool isSuffix(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        if (m > n) return false;
        for (int i = 0; i < m; i++) if (str1[m - i - 1] != str2[n - i - 1])
            return false;
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += (isPrefix(words[i], words[j]) && isSuffix(words[i], words[j]));
            }
        }
        return ans;
    }
};
