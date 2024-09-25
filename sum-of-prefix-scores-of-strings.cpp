// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

// Brute Force - TLE
class Solution {
public:
    void getPrefixes(unordered_map<string, int> &umap, string str) {
        for (int i = 0; i < str.size(); i++) {
            string temp = str.substr(0, i + 1);
            umap[temp]++;
        }
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> umap;
        vector<int> res;

        for (auto itr: words) getPrefixes(umap, itr);

        for (auto itr: words) {
            int sum = 0;
            for (int i = 1; i <= itr.size(); i++) {
                sum += umap[itr.substr(0, i)];
            }
            res.push_back(sum);
        }
        return res;
    }
};


// Trie 
class TrieNode {
public:
    unordered_map<char, pair<int, TrieNode*>> children;
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string str) {
        TrieNode* node = root;

        for (char digit: str) {
            if (node->children.find(digit) == node->children.end()) {
                node->children[digit] = {0, new TrieNode()};
            }
            node->children[digit].first += 1;
            node = node->children[digit].second;
        }
    }

    int findSum(string str) {
        TrieNode* node = root;

        int sum = 0;
        for (char dig: str) {
            if (node->children.find(dig) != node->children.end()) {
                sum += node->children[dig].first;
                node = node->children[dig].second;
            } else {
                break;
            }
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        for (string itr : words) {
            trie.insert(itr);
        }

        int n = words.size();
        vector<int> res;

        for (auto itr: words) res.push_back(trie.findSum(itr));
    
        return res;
    }
};
