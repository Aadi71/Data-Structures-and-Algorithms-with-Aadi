// https://leetcode.com/problems/unique-paths/


// T.C: O(M x N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        for(int i = 0; i<m; i++) matrix[i][n - 1] = 1;
        for(int j = 0; j<n; j++) matrix[m - 1][j] = 1;
        for(int i = m - 2; i>=0; i--){
            for(int j = n - 2; j>=0; j--){
                matrix[i][j] = matrix[i][j + 1] + matrix[i + 1][j];
            }
        }
        return matrix[0][0];
    }
};

