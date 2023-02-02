// https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int o = 0;
        unordered_map<int, int> umap;
        for(int i = 0; i<order.length(); i++) {umap[order[i]] = o; o++;}
        for(int i = 0; i<words.size() - 1; i++){
            int j = 0;
            while(j < words[i].length()){
                if(j >= words[i + 1].length()) return false;
                else if(umap[words[i][j]] < umap[words[i + 1][j]]) break;
                else if(umap[words[i][j]] > umap[words[i + 1][j]]) return false;
                j++;
            }
        }
        return true;
    }
};
