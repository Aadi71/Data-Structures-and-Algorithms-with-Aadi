// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

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
