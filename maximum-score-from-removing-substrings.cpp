// https://leetcode.com/problems/maximum-score-from-removing-substrings/

class Solution {
public:
    int solve(int val, string abOrba, string &s) {
        int ans = 0;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++) {
            if (!st.empty() && s[i] == abOrba[1] && st.top() == abOrba[0]) {
                st.pop();
                ans++;
            } else {
                st.push(s[i]);
            }
        }
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return ans * val;
    }
    int maximumGain(string s, int x, int y) {
        if (x > y) {
            return solve(x, "ab", s) + solve(y, "ba", s);
        } else {
            return solve(y, "ba", s) + solve(x, "ab", s);
        }
    }
};
