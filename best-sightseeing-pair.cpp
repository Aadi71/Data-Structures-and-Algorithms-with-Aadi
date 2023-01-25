// https://leetcode.com/problems/best-sightseeing-pair/

// Brute Force - TLE Not Accepted.
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = INT_MIN;
        int n = values.size();
        for(int i = 0; i<n - 1; i++){
            for(int j = i + 1; j<n; j++){
                maxi = max(maxi, values[i] + values[j] + i - j);
            }
        }
        return maxi;
    }
};


// Optimized. 
// We have to think this problem like two different elements that we need to take care of, (values[i] + i) and (values[j] - j)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0], maxj = INT_MIN;   
        for(int i = 1; i<values.size(); i++){
            maxj = max(maxj, maxi + values[i] - i);
            maxi = max(maxi, values[i] + i);
        }
        return maxj;
    }
};
