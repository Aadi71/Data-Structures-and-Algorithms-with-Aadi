// https://leetcode.com/problems/making-a-large-island/

class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i<=n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    bool isValid(int i, int j, int n){
        if(i >= 0 && j >= 0 && i < n && j < n) return true;
        return false;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int a[] = {-1, 1, 0, 0};
        int b[] = {0, 0, -1, 1};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k<4; k++){
                    int inew = i + a[k]; int jnew = j + b[k];
                    if(isValid(inew, jnew, n) && grid[inew][jnew] == 1){
                        int node = i * n + j;
                        int temp = inew * n + jnew;
                        ds.unionBySize(node, temp);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) continue;
                set<int> s;
                for(int k = 0; k<4; k++){
                    int inew = i + a[k]; int jnew = j + b[k];
                    if(isValid(inew, jnew, n) && grid[inew][jnew] == 1) s.insert(ds.findUPar(inew * n + jnew));
                }
                int total = 1;
                for(auto it: s) total += ds.size[it];
                ans = max(total, ans);
            }
        }
        for(int i = 0; i < n * n; i++) ans = max(ans, ds.size[ds.findUPar(i)]);
        return ans;
    }
};
