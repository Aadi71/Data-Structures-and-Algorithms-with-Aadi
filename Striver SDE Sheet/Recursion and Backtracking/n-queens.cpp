// https://leetcode.com/problems/n-queens/

class Solution {
public:

    bool isSafe(vector<string> &v, int row, int col, int n){
        int a = row;
        int b = col;
        while(row >= 0 && col >= 0) if(v[row--][col--] == 'Q') return false;
        row = a; col = b;
        while(col >= 0) if(v[row][col--] ==  'Q') return false;
        row = a; col = b;
        while(row < n && col >= 0) if(v[row++][col--] == 'Q') return false;
        return true;
    }

    void solve(vector<vector<string>> &ans, vector<string> &v, int n, int col){
        if(col == n){
            ans.push_back(v);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(v, row, col, n)){
                v[row][col] = 'Q';
                solve(ans, v, n, col + 1);
                v[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n, '.');
        for(int i = 0; i<n; i++) v[i] = s;
        solve(ans, v, n, 0);
        return ans;
    }
};
