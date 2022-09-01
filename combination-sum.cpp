// https://leetcode.com/problems/combination-sum/


class Solution {
public:
    void solve(int i, vector<vector<int>> &res, vector<int>& candidates, int target, vector<int>& temp){
        if(i == candidates.size()){
            if(target == 0) res.push_back(temp);
            return;
        }
        if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            solve(i, res, candidates, target - candidates[i], temp);
            temp.pop_back();
        }
        solve(i + 1, res, candidates, target, temp);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, res, candidates, target, temp);
        return res;
    }
};
