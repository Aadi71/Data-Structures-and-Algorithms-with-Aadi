// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void solve(int ind, vector<vector<int>> &ans, int target, vector<int> &candidates, vector<int> temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i<candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(i + 1, ans, target - candidates[i], candidates, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        solve(0, ans, target, candidates, {});
        return ans;
    }
};
