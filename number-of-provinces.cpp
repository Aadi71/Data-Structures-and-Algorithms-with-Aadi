// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, vector<int> &vis, int i){
        vis[i] = 1;
        for(int j = 0; j<isConnected[i - 1].size(); j++){
            if(isConnected[i - 1][j] == 1 && !vis[j + 1]){
                vis[j + 1] = 1;
                DFS(isConnected, vis, j + 1);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n + 1, 0);
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(!vis[i]){
                DFS(isConnected, vis, i);
                ans++;
            }
        }
        return ans;
    }
};
