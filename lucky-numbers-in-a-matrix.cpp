// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

// TC: O(M*N), SC: O(M)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        unordered_set<int> minRow;
        int mini;
        for(int i = 0; i < m; i++) {
            mini = INT_MAX;
            for(int j = 0; j < n; j++) {
                mini = min(mini, matrix[i][j]);
            }
            minRow.insert(mini);
        }
        for(int i = 0; i < n; i++) {
            mini = INT_MIN;
            for(int j = 0; j < m; j++) {
                mini = max(mini, matrix[j][i]);
            }
            if (minRow.contains(mini)) ans.push_back(mini);
        }
        return ans;
    }
};
