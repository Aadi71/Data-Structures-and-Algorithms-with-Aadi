// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

// Using Hashset. 
class Solution {
public:
    void getPrefixes(int n, unordered_set<string>& umap) {
        string str = to_string(n);
        for (int i = 0; i < str.size(); i++) {
            umap.insert(str.substr(0, i + 1));
        }
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> umap;
        
        for (auto itr : arr1) 
            if (umap.find(to_string(itr)) == umap.end())
                getPrefixes(itr, umap);
        

        int ans = 0;

        for (auto itr : arr2) {
            string str = to_string(itr);
            for (int i = 0; i < str.size(); i++) {
                string prefix = str.substr(0, i + 1);
                if (umap.find(prefix) != umap.end()) {
                    ans = max(ans, (int)prefix.size());
                }
            }
        }
        return ans;
    }
};

// Using Trie
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* node = root;
        string str = to_string(num);
        for (char digit: str) {
            if (!node->children[digit]) {
                node->children[digit] = new TrieNode();
            }
            node = node->children[digit];
        }
    }

    int findLongest(int num) {
        TrieNode* node = root;
        string str = to_string(num);
        int len = 0;
        for (char dig: str) {
            if (node->children[dig]) {
                len++;
                node = node->children[dig];
            } else {
                break;
            }
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for (int num : arr1) {
            trie.insert(num);
        }

        int longestPrefix = 0;

        for (int num : arr2) {
            int len = trie.findLongest(num);
            longestPrefix = max(longestPrefix, len);
        }

        return longestPrefix;
    }
};

