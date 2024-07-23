// https://leetcode.com/problems/sort-array-by-increasing-frequency/

// TC: O(NlogN), SC: O(N)

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto itr: nums) freq[itr]++;
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) return a > b;
            return freq[a] < freq[b];
        });
        return nums;
    }
};
