// https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    queue<pair<int, int>> q;
    vector<int> a = {-1, 1, 0, 0};
    vector<int> b = {0, 0, -1, 1};
    void DFS(vector<vector<int>>& grid, int i, int j){
        grid[i][j] = -1;
        for(int k = 0; k<4; k++){
            int inew = i + a[k];
            int jnew = j + b[k];
            if(inew >= 0 && jnew >= 0 && inew < grid.size() && jnew < grid.size() && grid[inew][jnew] == 1){
                q.push({inew, jnew});
                DFS(grid, inew, jnew);
            }
        }
    }
    int BFS(vector<vector<int>>& grid){
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            ans++;
            while(s--){
                auto f = q.front();
                q.pop();
                for(int k = 0; k<4; k++){
                    int inew = a[k] + f.first;;
                    int jnew = b[k] + f.second;;
                    if(inew >= 0 && jnew >= 0 && inew < grid.size() && jnew < grid.size()){
                        if(grid[inew][jnew] == 1) return ans;
                        else if(grid[inew][jnew] == 0){
                            grid[inew][jnew] = -1;
                            q.push({inew, jnew});
                        }
                    }
                }
            }
        }
        return -1;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = false;
        int i, j;
        for(i = 0; i<n; i++){
            for(j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        DFS(grid, q.front().first, q.front().second);
        int ans = BFS(grid);
        return ans == 1 ? 1 : ans - 1;
    }
};
