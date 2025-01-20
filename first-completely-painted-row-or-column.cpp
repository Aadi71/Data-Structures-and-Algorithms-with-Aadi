// https://leetcode.com/problems/first-completely-painted-row-or-column

// TC: O(m*n), SC: O(m*n)
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        unordered_map<int, pair<int, int>> location;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                location[mat[i][j]] = {i, j};
            }
        }

        int ans = 0;
        for (int i = 0; i < m * n; i++) {
            pair<int, int> loc = location[arr[i]];
            rows[loc.first]++;
            cols[loc.second]++;
            if (rows[loc.first] == n || cols[loc.second] == m) return ans;
            ans++;
        }
        return -1;
    }
};

// TC: O(m*n), SC: O(m*n), Different Approach
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = INT_MAX;

        unordered_map<int, int> elementVsIndex;

        for (int i = 0; i < m * n; i++) elementVsIndex[arr[i]] = i;

        for (int i = 0; i < m; i++) {
            int tempMax = INT_MIN;
            for (int j = 0; j < n; j++) {
                tempMax = max(tempMax, elementVsIndex[mat[i][j]]);
            }
            ans = min(ans, tempMax);
        }

        for (int i = 0; i < n; i++) {
            int tempMax = INT_MIN;
            for (int j = 0; j < m; j++) {
                tempMax = max(tempMax, elementVsIndex[mat[j][i]]);
            }
            ans = min(ans, tempMax);
        }

        
        return ans;
    }
};