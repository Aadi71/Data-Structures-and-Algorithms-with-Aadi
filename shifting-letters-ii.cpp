// https://leetcode.com/problems/shifting-letters-ii/

// Brute Force
class Solution {
public:
    string shiftingLetters(string str, vector<vector<int>>& shifts) {
        for (int i = 0; i < shifts.size(); i++) {
            int s = shifts[i][0];
            int e = shifts[i][1];
            int d = shifts[i][2];

            for (int j = s; j <= e; j++) {
                char ch = str[j];
                if (d == 1 && ch == 'z') ch = 'a';
                else if (d == 0 && ch == 'a') ch = 'z';
                else if (d == 0) ch = ch - 1;
                else ch = ch + 1;
                str[j] = ch;
            }
        }
        return str;
    }
};

//  n be the size of the string s and m the size of the shifts array.
// Optimized Solution, TC: O(n+m)
class Solution {
public:
    string shiftingLetters(string str, vector<vector<int>>& shifts) {
        int n = str.size();
        vector<int> moves(n, 0);
        for (int i = 0; i < shifts.size(); i++) {
            int s = shifts[i][0];
            int e = shifts[i][1];
            int d = shifts[i][2];

            if (d == 0) {
                moves[s]--;
                if (e + 1 < n) moves[e + 1]++;
            } else {
                 moves[s]++;
                if (e + 1 < n) moves[e + 1]--;
            }
        }

        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += moves[i];
            prefixSum %= 26;
            
            if (prefixSum < 0) prefixSum += 26;
            str[i] = 'a' + (str[i] - 'a' + prefixSum) % 26;
        }
        return str;
    }
};
