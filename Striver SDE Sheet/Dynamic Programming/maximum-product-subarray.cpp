// https://leetcode.com/problems/maximum-product-subarray/

// Brute Force, Time Limit Exceeded. TC: O(N^3)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int temp = 1;
                for(int k = i; k <= j; k++){
                    temp *= nums[k];
                }
                maximum = max(maximum, temp);
            }
        }
        return maximum;
    }
};

// Optimized Brute Force. TC: O(N^2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                maximum = max(maximum, temp);
                temp *= nums[j];
            }
            maximum = maximum > temp ? maximum : temp;
        }
        return maximum;
    }
};

// Implemented Modified Kadane's Algorithm. TC: O(N)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum = nums[0], a = nums[0], b = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int temp = max({nums[i], a * nums[i], b * nums[i]});
            b = min({nums[i], a * nums[i], b * nums[i]});
            a = temp;
            maximum = max(maximum, a);
        }
        return maximum;
    }
};
