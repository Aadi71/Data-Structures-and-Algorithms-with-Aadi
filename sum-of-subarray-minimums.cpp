// Brute Force: O(N^3)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++){
                int mini = INT_MAX;
                for(int k = i; k <= j; k++) {
                    mini = min(mini, arr[k]);
                }
                ans = (ans + mini) % MOD;
            }
        }
        return ans;
    }
};


// Brute Force Optimized: O(N^2)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int mini = INT_MAX;
            for(int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                ans = (ans + mini) % MOD;
            }
        }
        return ans;
    }
};


// Optimized Solution: O(N) - Montonic Sequence
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(INT_MIN);
        int n = arr.size();
        vector<int> v;
        int MOD = 1e9 + 7;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while(!v.empty() && arr[i] < arr[v.back()]) {
                int ind = v.back();
                v.pop_back();
                long long val = arr[ind];
                int rightCount = i - ind;
                int leftCount = v.empty() ? ind + 1 : ind - v.back();
                ans = ((ans + val * rightCount * leftCount) % MOD);
            }
            v.push_back(i);
        }
        return ans;
    }
};
