// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int ans = 0;
        vector<int> a = {0, 0, -1, 1};
        vector<int> b = {1, -1, 0, 0};
        while(!q.empty()){
            ans++;
            int s = q.size();
            while(s--){
                auto f = q.front();
                q.pop();
                for(int k = 0; k<4; k++){
                    int i = f.first + a[k];
                    int j = f.second + b[k];
                    if(i >= 0 && j >= 0 && i < m && j < n && maze[i][j] == '.'){
                        if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && (i != entrance[0] || j != entrance[1])) return ans;
                        else{
                            q.push({i, j});
                            maze[i][j] = '+';
                        }
                    }
                }
            }
        } 
        return -1;
    }
};
