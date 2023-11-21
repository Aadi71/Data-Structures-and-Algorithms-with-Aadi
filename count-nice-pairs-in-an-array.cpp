// https://leetcode.com/problems/count-nice-pairs-in-an-array/

// Naive Approach - Time Limit Exceeded
// T.C: O(n^2)
class Solution {
public:
    int rev(int n) {
        int s = 0;
        while(n) {
            int r = n % 10;
            s = (s * 10) + r;
            n /= 10;
        }
        return s;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 0; i < n; i++) v.push_back(rev(nums[i]));

        int ans = 0; 

        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if (v[i] + nums[j] == nums[i] + v[j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};


// Optimized approach using HashMap and Pair Count.
// T.C: O(n)
class Solution {
public:
    int rev(int n) {
        int s = 0;
        while(n) {
            int r = n % 10;
            s = (s * 10) + r;
            n /= 10;
        }
        return s;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long mod = 1e9 + 7;
        unordered_map<int, long long> umap;

        for (int i = 0; i < n; i++) {
            umap[nums[i] - rev(nums[i])]++;
        }

        for(auto itr: umap) {
            ans += (itr.second * (itr.second - 1) / 2) % mod;
        }
        return ans % mod;
    }
};
