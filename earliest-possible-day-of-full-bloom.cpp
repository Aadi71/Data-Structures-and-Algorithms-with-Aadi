// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

class Solution {
public:
    static bool sortbysec(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> v;
        int n = plantTime.size();
        for(int i = 0; i<n; i++) v.push_back(make_pair(plantTime[i], growTime[i]));
        
        sort(v.begin(), v.end(), sortbysec);
        
        int j = 0;
        int maxi = INT_MIN;
        
        for(int i = 0; i<n; i++){
            j += v[i].first;
            int temp = j + v[i].second;
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};
