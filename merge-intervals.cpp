// https://leetcode.com/problems/merge-intervals/

// Brute Force - Sorting and traversing - T.C: O(nlog(n)) + O(N^2)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        int i = 0, j = 0;
        while(i < intervals.size()){
            int a = intervals[i][0];
            int b = intervals[i][1];
            for(j = i+1; j<intervals.size(); j++){
                if(b >= intervals[j][0]) b = b > intervals[j][1] ? b : intervals[j][1];
                else break;
            }
            i = j;
            v.push_back({a, b});
        }
        return v;
    }
};

// Optimized
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {{}};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        int i = 0;
        vector<int> temp(2);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        while(i < intervals.size()){
            if(temp[1] >= intervals[i][0]) {
                temp[1] = temp[1] > intervals[i][1] ? temp[1] : intervals[i][1]; 
            }
            else{
                v.push_back({temp[0], temp[1]});
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
            i++;
        }
        v.push_back({temp[0], temp[1]});
        return v;
    }
};
