// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size() && newInterval[0] > intervals[i][0]) i++;
        intervals.insert(intervals.begin() + i, newInterval);
        int a = intervals[0][0], b = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++){
            if(b < intervals[i][0]){
                res.push_back({a, b});
                a = intervals[i][0];
                b = intervals[i][1];
            } 
            if(b <= intervals[i][1]) b = intervals[i][1];
        }
        res.push_back({a, b});
        return res;
    }
};
