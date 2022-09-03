// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
public:
    void dfs(int n, int k, vector<int> &ans, int dig){
        if(n == 0) ans.push_back(dig);
        else{
            int num = dig % 10;
            if(num + k <= 9) dfs(n-1, k, ans, dig * 10 + num + k);
            if(k != 0 && num >= k) dfs(n-1, k, ans, dig * 10 + num - k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i<=9; i++)
            dfs(n-1, k, ans, i);
        return ans;
    }
};
