// https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &flag){
        grid2[i][j] = 2;
        if(grid1[i][j] != 1) flag = false;
        int a[] = {0, 0, -1, 1};
        int b[] = {-1, 1, 0, 0};

        for(int k = 0; k<4; k++){
            int inew = i + a[k];
            int jnew = j + b[k];
            if(inew >= 0 && jnew >= 0 && inew < grid1.size() && jnew < grid1[0].size() && grid2[inew][jnew] == 1){
                dfs(grid1, grid2, inew, jnew, flag);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid2[0].size();
        bool flag = true;
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid2[i][j] == 1){
                    flag = true;
                    dfs(grid1, grid2, i, j, flag);
                    if(flag == true) ans++;
                }
            }        
        }
        return ans;
    }
};
