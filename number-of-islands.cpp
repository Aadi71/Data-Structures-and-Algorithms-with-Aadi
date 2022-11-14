// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int a[] = {0, 0, -1, 1};
        int b[] = {-1, 1, 0, 0};
        int sum = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1'){
                    q.push({i, j});
                    grid[i][j] = '2';
                    while(!q.empty()){
                        int si = q.size();
                        while(si--){
                            for(int k = 0; k<4; k++){
                                int ip = q.front().first + a[k];
                                int iq = q.front().second + b[k];
                                if(ip >= 0 && iq >= 0 && ip < m && iq < n && grid[ip][iq] == '1'){
                                    grid[ip][iq] = '2';
                                    q.push({ip, iq});
                                }
                            }
                            q.pop();
                        }
                    }
                    sum++;
                }
            }
        }
        return sum;
    }
};
