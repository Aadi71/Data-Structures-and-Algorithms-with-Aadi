// https://leetcode.com/problems/combination-sum/


class Solution {
public:
    void findNumbers(vector<int>& c, vector<int> &r, vector<vector<int>> &v, int sum, int i){
        if(sum == 0){
            v.push_back(r);
            return;
        }
        
        while(i < c.size() && sum - c[i] >=0){
            r.push_back(c[i]);
            findNumbers(c, r, v, sum - c[i], i);
            for(int i = 0; i<r.size(); i++) cout<<r[i]<<" ";
            cout<<endl;
            i++;
            
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        
        vector<int> r;
        vector<vector<int>> v;
        
        findNumbers(c, r, v, target, 0);
        return v;
    }
};
