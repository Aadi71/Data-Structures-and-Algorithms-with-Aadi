// Brute Force: O(N) Solution
// Formula: ans = Z(l) + O(r) ; maximizing this

class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') totalOnes++;
        }

        int ans = INT_MIN;
        int currZeros = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') currZeros++;
            else totalOnes--;
            ans = max(ans, currZeros + totalOnes);
        }
        return ans;
    }
};


// One Pass Solution, Instead of maximing Z(l) + O(r), we will break O(r) into O(total) - O(l).
// therefore, ans = Z(l) + O(total) - O(l), now O(total) is constant, thus we will maximize: Z(l) - O(l)

class Solution {
public:
    int maxScore(string s) {
        int currOnes = 0;
        int currZeros = 0;
        int n = s.size();

        int ans = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') currZeros++;
            else currOnes++;
            ans = max(ans, currZeros - currOnes);
        }
        if (s[n - 1] == '1') currOnes++;
        return ans + currOnes;
    }
};
