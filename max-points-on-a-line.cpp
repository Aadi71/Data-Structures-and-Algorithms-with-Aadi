// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int i = 0;
        int maxi = 2;
        while(i < n){
            unordered_map<double, int> umap;
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                umap[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
            }
            for(auto& it: umap) maxi = max(maxi, it.second + 1);
            i++;
        }
        return maxi;
    }
};
