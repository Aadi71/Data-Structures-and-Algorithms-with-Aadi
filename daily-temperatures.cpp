// https://leetcode.com/problems/daily-temperatures

// Brute Force (TLE): O(N^2)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans;
        int n = t.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(j == n) {
                    ans.push_back(0);
                    break;
                }
                if(t[j] > t[i]) {
                    ans.push_back(j - i);
                    break;
                }
            }
        }
        return ans;
    }
};


// Time Optimized Solution using Monotonic Stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> st;
        int n = t.size();
        vector<int> res(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            if (st.empty()) st.push({t[i], i});
            else {
                while(!st.empty() && st.top().first <= t[i]) st.pop();
                if (st.empty()) st.push({t[i], i});
                else {
                    res[i] = st.top().second - i;
                    st.push({t[i], i});
                }
            }
        }
        return res;
    }
};
