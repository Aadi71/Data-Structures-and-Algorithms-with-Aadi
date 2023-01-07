// https://leetcode.com/problems/number-of-provinces/

// Union Find taking Constant Time Complexity
class DisjointSet{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i<=n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i, j);
                }
            }
        }
        int c = 0;
        for(int i = 0; i<n; i++){
            if(ds.findUPar(i) == i) c++;
        }
        return c;
    }
};



// DFS Solution taking O(V + E) time complexity
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
