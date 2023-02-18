// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool isPalindromie(string s, int start, int end){
        while(start <= end) if(s[start++] != s[end--]) return false;
        return true; 
    }
  
    void solve(string s, int ind, vector<vector<string>> &ans, vector<string> temp){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }
      
        for(int i = ind; i<s.size(); i++){
            if(isPalindromie(s, ind, i)){
                temp.push_back(s.substr(ind, i - ind + 1));
                solve(s, i + 1, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        solve(s, 0, ans, {});
        return ans;
    }
};
