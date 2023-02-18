// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// Brute Force - Using Power Set. TC: O(2^N X N) + O(N X log(N))

class Solution{
public:
    vector<int> subsetSums(vector<int> arr, int N){
        int total = 1 << N;
        vector<int> v;
        for(int i = 0; i < total; i++){
            int sum = 0;
            for(int j = 0; j < N; j++) if(i & (1 << j)) sum += arr[j];
            v.push_back(sum);
        }
        sort(v.begin(), v.end());
        return v;
    }
};

// Optimized approach using Recursion with the concept of pick and not pick. TC: (2^N) + (NlogN)

class Solution{
public:
    void solve(int ind, int sum, int N, vector<int> &arr, vector<int> &ans){
        if(ind == N){
            ans.push_back(sum);
            return;
        }
        solve(ind + 1, sum, N, arr, ans);
        solve(ind + 1, sum + arr[ind], N, arr, ans);
    }
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> ans;
        solve(0, 0, N, arr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
