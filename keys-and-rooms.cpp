// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        queue<int> q;
        vis[0] = 1;
        for(auto i: rooms[0]){
            q.push(i);
            vis[i] = 1;
        }
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int f = q.front();
                q.pop();
                for(auto i: rooms[f]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
        for(auto i: vis) if(i == 0) return false;
        return true;
    }
};
