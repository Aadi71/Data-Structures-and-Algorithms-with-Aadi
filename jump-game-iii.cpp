// https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return 1;
        queue<int> q;
        q.push(start);
        unordered_set<int> s;
        s.insert(start);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            if(arr[f] == 0) return 1;
            if(f + arr[f] < arr.size() && s.find(f + arr[f]) == s.end()){
                s.insert(f + arr[f]);
                q.push(f + arr[f]);
            }
            if(f - arr[f] >= 0 && s.find(f - arr[f]) == s.end()){
                s.insert(f - arr[f]);
                q.push(f - arr[f]);
            }
        }
        return 0;
    }
};
