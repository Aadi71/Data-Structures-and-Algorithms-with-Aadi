// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

// Naive Approach - 1
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> temp(n + 1);
        for(int i = 0; i < n; i++){
            temp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;

        for(int i = 0; i < n + 1; i++){
            if(temp[i].size() == 0) continue;
            vector<int> t;
            for(int j = 0; j < temp[i].size(); j++){
                t.push_back(temp[i][j]);
                if((j + 1) % i == 0){
                    ans.push_back(t);
                    t.clear();
                }
            }

        }
        return ans;
    }
}

// Approach - 2 (Space Optimized)

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < n; i++){
            umap[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it: umap){
            vector<int> t;
            for(int j = 0; j < it.second.size(); j++){
                t.push_back(it.second[j]);
                if((j + 1) % it.first == 0){
                    ans.push_back(t);
                    t.clear();
                }
            }
        }
        return ans;
    }
};
