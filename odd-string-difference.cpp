// https://leetcode.com/problems/odd-string-difference/

class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        int s = words[0].length();
        unordered_map<string, vector<string>> umap;
        for(int i = 0; i<n; i++){
            string temp = "";
            for(int j = 1; j<s; j++){
                temp += to_string(words[i][j] - words[i][j - 1]) + "-";
            }
            umap[temp].push_back(words[i]);
        }
        for(auto i: umap){
            if(i.second.size() == 1) return i.second[0];
        }
        return "";
    }
};
