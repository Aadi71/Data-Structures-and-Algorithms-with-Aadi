// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words;
        for(int i = 0; i<wordList.size(); i++){
            words.insert(wordList[i]);
        }
        int n = beginWord.length();
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                string orig = q.front().first;
                int t = q.front().second;
                q.pop();
                for(int i = 0; i<n; i++){
                    char w = orig[i];
                    for(int j = 0; j < 26; j++){
                        orig[i] = char(97 + j);
                        auto it = words.find(orig);
                        if(it != words.end()){
                            if(orig == endWord) return t + 1;
                            q.push({orig, t + 1});
                            words.erase(orig);
                        }
                    }
                    orig[i] = w; 
                }
            }
        }
        return 0;
    }
};
