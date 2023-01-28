// https://leetcode.com/problems/maximal-network-rank/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> v(n + 1, vector<int> (n + 1, 0));
        for(int i = 0; i<roads.size(); i++){
            v[roads[i][0]][roads[i][1]] = 1;
            v[roads[i][1]][roads[i][0]] = 1;
            v[roads[i][0]][n]++; v[roads[i][1]][n]++;
        }
        int maxi = INT_MIN;
        for(int i = 0; i<n-1; i++){
            for(int j = i + 1; j<n; j++){
                int temp = v[i][n] + v[j][n];
                if(v[i][j] == 1 && v[j][i] == 1) temp--;
                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }
};
