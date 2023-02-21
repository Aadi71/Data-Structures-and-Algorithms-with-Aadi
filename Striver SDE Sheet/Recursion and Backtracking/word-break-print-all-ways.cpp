// https://www.codingninjas.com/codestudio/problems/983635?

#include <bits/stdc++.h> 
using namespace std;

void solve(unordered_set<string> &uset, vector<string> &ans, string s, string temp){
    if(s.size() == 0){
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    for(int i = 1; i<=s.size(); i++){
        if(uset.find(s.substr(0, i)) == uset.end()) continue;
        solve(uset, ans, s.substr(i), temp + s.substr(0, i) + " ");
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary){
    unordered_set<string> uset;
    uset.insert(dictionary.begin(), dictionary.end());
    vector<string> ans;
    solve(uset, ans, s, "");
    return ans;
}
