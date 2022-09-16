// https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        if(arr.size() % 2) return {};
        vector<int> res;
        
        map<int, int> umap;
        for(auto x: arr) umap[x]++;
        
        for(auto x: umap){
            while(umap[x.first] > 0){
                if(umap[x.first] == 0) continue;
                else if(umap[x.first * 2] == 0) return {};
                else if(umap[x.first * 2] && umap[x.first]){
                    res.push_back(x.first);
                    umap[x.first * 2]--;
                    umap[x.first]--;
                }
            }
        }
        return res;
    }
};
