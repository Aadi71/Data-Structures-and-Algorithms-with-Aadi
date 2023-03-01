// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Brute Force. TC: O(n^2)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int ans = 0;
        for(int i = 0; i < n; i++){
            int temp = 0;
            for(int j = i; j < n; j++){
                temp += A[j];
                if(temp == 0) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

// TC: O(N). We are simply storing the index of all prefix sum which we encountered earliest and we encounter same sum after then it simply means that all elements till now add to zero.
class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        unordered_map<int, int> umap;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0) ans = i + 1;
            else{
                if(umap.find(sum) != umap.end()) ans = max(ans, i - umap[sum]);
                else umap[sum] = i;
            }
        }
        return ans;
    }
};
