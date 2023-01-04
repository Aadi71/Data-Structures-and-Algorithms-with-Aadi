// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> umap;
        for(int i = 0; i<tasks.size(); i++) umap[tasks[i]]++;
        int ans = 0;
        for(auto x: umap){
            if(x.second == 1) return -1;
            if(x.second % 3 == 0) ans += x.second / 3;
            else ans += x.second / 3 + 1;
        }
        return ans;
    }
};
