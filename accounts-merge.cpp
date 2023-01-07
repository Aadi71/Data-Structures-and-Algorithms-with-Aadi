// https://leetcode.com/problems/accounts-merge/

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mail;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string m = accounts[i][j];
                if(mail.find(m) == mail.end()) mail[m] = i;
                else ds.unionBySize(i, mail[m]);
            }
        }
        vector<string> merge[n];
        for(auto it: mail){
            string m = it.first;
            int node = ds.findUPar(it.second);
            merge[node].push_back(m);
        }
        vector<vector<string>> res;
        for(int i = 0; i<n; i++){
            if(merge[i].size() == 0) continue;
            sort(merge[i].begin(), merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: merge[i]) temp.push_back(it);
            res.push_back(temp);
        }
        return res;
    }
};
