// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
    
        // Accepted Solution
        
        sort(special.begin(), special.end());
        int maxi = special[0] - bottom;
        for(int i = 1; i<special.size(); i++){
            maxi = max(maxi, special[i] - special[i - 1] - 1);
        }
        maxi = max(maxi, top - special[special.size() - 1]);
        return maxi;
        
        // This got Memory Limit Exceeded Error
        
        // int n = top - bottom + 1;
        // vector<int> v(n, 0);
        // for(int i = 0; i<special.size(); i++){
        //     v[special[i] - bottom] = 1;
        // }
        // int maxi = 0;
        // int i = 0;
        // while(i < n){
        //     int temp = 0;
        //     while(i < n && v[i] != 1){
        //         temp++;
        //         i++;
        //     }
        //     i++;
        //     maxi = max(maxi, temp);
        // }
        // return maxi;
        
        // This got Time Limit Exceeded Error
        
        // sort(special.begin(), special.end());
        // int maxi = 0;
        // int temp = 0;
        // int j = 0;
        // for(int i = bottom; i<= top; i++){
        //     if(j < special.size() && i == special[j]){
        //         maxi = max(maxi, temp);
        //         j++;
        //         temp = 0;
        //     }
        //     else{
        //         temp++;
        //     }
        // }
        // maxi = max(maxi, temp);
        // return maxi;
    }
};
