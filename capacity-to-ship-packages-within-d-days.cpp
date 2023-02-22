// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// Brute Force, Time Limit Exceeded. TC: O(N^2)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0, maxElement = 0;
        for(int i = 0; i < weights.size(); i++){
            total += weights[i];
            maxElement = maxElement > weights[i] ? maxElement : weights[i];
        }
        int low = maxElement, high = total;
        
        for(int i = maxElement; i <= total; i++){
            int d = 1, temp = 0;
            for(int j = 0; j < weights.size(); j++){
                temp += weights[j];
                if(temp > i){
                    d++;
                    temp = weights[j];
                }
            }
            if(d <= days) return i;
        }
        return -1;
    }
};

// Optimized Solution, Reducing search space by Binary Search. TC: O(NlogN)
class Solution {
public:
    bool validity(int w, vector<int> &weights, int days){
        int tempDay = 1;
        int currW = 0;
        for(int i = 0; i < weights.size(); i++){
            currW += weights[i];
            if(currW > w){
                tempDay++;
                currW = weights[i];
            }
        }
        return tempDay <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0, maxElement = 0;
        for(int i = 0; i < weights.size(); i++){
            total += weights[i];
            maxElement = maxElement > weights[i] ? maxElement : weights[i];
        }
        int low = maxElement, high = total;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(validity(mid, weights, days)) high = mid - 1;
            else low = mid + 1; 
        }
        return low;
    }
};
