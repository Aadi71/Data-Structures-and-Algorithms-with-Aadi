// https://leetcode.com/problems/single-number-ii/

// Brute Force with HashMap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i = 0; i< nums.size(); i++) umap[nums[i]]++;
        for(auto i: umap) if(i.second == 1) return i.first;
        return -1;
    }
};

// Space Optimized - Using Bitwise operator, Basically we are setting bit which has extra bit. TC: O(32*N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(int j = 0; j < nums.size(); j++) {
                if (1 & (nums[j] >> i)) cnt++;
            }
            if (cnt % 3 == 1) ans = ans | (1 << i);
        }
        return ans;
    }
};


// Most Optimal in terms of Time Complexity, with O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int itr: nums) {
            ones = (ones ^ itr) & ~twos;
            twos = (twos ^ itr) & ~ones;
        }
        return ones;
    }
};
