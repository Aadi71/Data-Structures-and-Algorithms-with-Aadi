// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n + 1, 1);
        for(int i = 2; i < n + 1; i++){
            int total = 0;
            for(int j = 1; j < i + 1; j++){
                int left = j - 1;
                int right = i - j;
                total += v[left] * v[right];
            }
            v[i] = total;
        }
        return v[n];
    }
};
