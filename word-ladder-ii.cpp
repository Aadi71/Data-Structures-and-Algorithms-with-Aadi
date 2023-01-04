// https://practice.geeksforgeeks.org/problems/word-ladder-ii/
// This solution is not yet optimized for LeetCode Word Ladder II problem, it will require some more optimization which will be done in this code soon.


class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        queue<vector<string>> q;
        if(words.find(beginWord) == words.end() && words.find(endWord) == words.end()) return {};
        vector<string> v;
        v.push_back(beginWord);
        q.push(v);
        words.erase(beginWord);
        vector<string> temp;
        temp.push_back(beginWord);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                vector<string> v = q.front();
                string w = v[v.size() - 1];
                q.pop();
                if(w == endWord){
                    if(res.size() == 0) res.push_back(v);
                    else if(res[0].size() == v.size()) res.push_back(v);
                }
                for(int i = 0; i<beginWord.length(); i++){
                    char orig = w[i];
                    for(int j = 0; j<26; j++){
                        w[i] = char(97 + j);
                        if(words.find(w) != words.end()){
                            temp.push_back(w);
                            v.push_back(w);
                            q.push(v);
                            v.pop_back();
                        }
                    }
                    w[i] = orig;
                }
            }
            for(int i = 0; i<temp.size(); i++) words.erase(temp[i]);
            temp.clear();
        }
        return res;
    }
};
