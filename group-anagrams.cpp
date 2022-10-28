// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> orig;
        for(auto x: strs){
            map<char, int> temp;
            vector<string> v;
            for(auto i: x) temp[i]++;
            auto it = orig.find(temp);
            if(it != orig.end()) it -> second.push_back(x);
            else{
                v.push_back(x);
                orig.insert({temp, v});
            }
        }
        vector<vector<string>> res;
        for(auto it: orig) res.push_back(it.second);
        return res;
    }
};
