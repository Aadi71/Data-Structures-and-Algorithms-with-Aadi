// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    void solve(string digits, vector<string> &s, vector<string> &res, int i, string temp){
        if(i == digits.length()){
            res.push_back(temp);
            return;
        }

        for(int c = 0; c < s[(digits[i] - '0') - 2].length(); c++){
            temp += s[(digits[i] - '0') - 2][c];
            solve(digits, s, res, i + 1, temp);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> s = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        solve(digits, s, res, 0, "");
        return res;
    }
};
