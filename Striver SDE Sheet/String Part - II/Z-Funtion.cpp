// Z-Funtion : String Matching Algorithms/Pattern Searching

// Reference: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/3121002/find-the-index-of-the-first-occurrence-in-a-string/?orderBy=most_votes

// Brute Force: Naive Algorithm. TC: O(M * N)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0; 
        int j;
        int m = haystack.length();
        int n = needle.length();
        while(i < m){
            int k = i;
            j = 0;
            while(k < m && j < n){
                if(haystack[k] != needle[j]) break;
                j++; k++;
            }
            if(j == n) return i;
            i++;
        }
        return -1;
    }
};


// Rabin Karp: TC: O(M * N). But if we look its average time complexity, it is much better than Naive Algorithm. 
class Solution {
public:
    int hashValue(string string, int RADIX, int MOD, int m) {
        int ans = 0;
        long factor = 1;
        for (int i = m - 1; i >= 0; i--) {
            ans += ((int) (string[i] - 'a') * factor) % MOD;
            factor = (factor * RADIX) % MOD;
        }
        return ans % MOD;
    }

    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();
        if (n < m) return -1;

        // CONSTANTS
        int RADIX = 26;
        int MOD = 1000000033;
        long MAX_WEIGHT = 1;

        for (int i = 0; i < m; i++) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

        // Compute hash of needle
        long hashNeedle = hashValue(needle, RADIX, MOD, m), hashHay = 0;

        // Check for each m-substring of haystack, starting at index windowStart
        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
          // Compute hash of the First Substring
            if (windowStart == 0) hashHay = hashValue(haystack, RADIX, MOD, m);
          // Update Hash using Previous Hash Value in O(1)
            else hashHay = ((hashHay * RADIX) % MOD - ((int) (haystack[windowStart - 1] - 'a') * MAX_WEIGHT) % MOD + (int) (haystack[windowStart + m - 1] - 'a') + MOD) % MOD;
            // If the hash matches, Check Character by Character. 
            // Because of Mod, spurious hits can be there.
            if (hashNeedle == hashHay) {
                for (int i = 0; i < m; i++) {
                    if (needle[i] != haystack[i + windowStart]) break;
                    if (i == m - 1) return windowStart;
                }
            }
        }
        return -1;
    }
};

// KMP Algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {

        int m = needle.length();
        int n = haystack.length();

        if (n < m)
            return -1;

        // PREPROCESSING
        // longest_border array
        vector<int> longest_border(m);
        // Length of Longest Border for prefix before it.
        int prev = 0;
        // Iterating from index-1. longest_border[0] will always be 0
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[prev]) {
                // Length of Longest Border Increased
                prev += 1;
                longest_border[i] = prev;
                i += 1;
            } else {
                // Only empty border exist
                if (prev == 0) {
                    longest_border[i] = 0;
                    i += 1;
                }
                // Try finding longest border for this i with reduced prev
                else {
                    prev = longest_border[prev - 1];
                }
            }
        }

        // SEARCHING
        // Pointer for haystack
        int haystackPointer = 0;
        // Pointer for needle.
        // Also indicates number of characters matched in current window.
        int needlePointer = 0;

        while (haystackPointer < n) {
            if (haystack[haystackPointer] == needle[needlePointer]) {
                // Matched Increment Both
                needlePointer += 1;
                haystackPointer += 1;
                // All characters matched
                if (needlePointer == m) {
                    // m characters behind last matching will be start of window
                    return haystackPointer - m;
                }
            } else {
                if (needlePointer == 0) {
                    // Zero Matched
                    haystackPointer += 1;
                } else {
                    // Optimally shift left needlePointer. Don't change haystackPointer
                    needlePointer = longest_border[needlePointer - 1];
                }
            }
        }

        return -1;
    }
};




