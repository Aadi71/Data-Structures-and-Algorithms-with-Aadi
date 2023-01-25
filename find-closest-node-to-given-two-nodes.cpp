// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

class Solution {
public:
    void dfs(vector<int> edges, int sum, int i, vector<int> &v){
        while(i != -1 && v[i] == -1){
            v[i] = sum++;
            i = edges[i];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int res = -1, mini = INT_MAX;
        vector<int> vn1(n, -1), vn2(n, -1);
        dfs(edges, 0, node1, vn1);
        dfs(edges, 0, node2, vn2);
        for(int i = 0; i<n; i++){
            if(min(vn1[i], vn2[i]) >= 0 && max(vn1[i], vn2[i]) < mini){
                res = i;
                mini = max(vn1[i], vn2[i]);
            }
        }
        return res;
    }
};
