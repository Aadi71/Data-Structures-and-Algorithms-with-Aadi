// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    static bool cmp(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        map<char, int> m;
        for(auto x: s) m[x]++;
        vector<pair<char, int>> v;
        for(auto& it: m) v.push_back(it);
        sort(v.begin(), v.end(), cmp);
        string res = "";
        for(auto& it: v){
            int n = it.second;
            while(n--) res += it.first;
        }
        return res;
    }
};
