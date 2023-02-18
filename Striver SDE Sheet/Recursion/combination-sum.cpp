// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void solve(vector<vector<int>> &v, vector<int> temp, vector<int> &candidates, int target, int ind){
        if(ind == candidates.size()){
            if(target == 0) v.push_back(temp);
            return;
        }
      
        if(target == 0){
            v.push_back(temp);
            return;
        }

        if(target >= candidates[ind]){
            temp.push_back(candidates[ind]);
            solve(v, temp, candidates, target - candidates[ind], ind);
            temp.pop_back();
        }
        solve(v, temp, candidates, target, ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        solve(v, {}, candidates, target, 0);
        return v;
    }
};
