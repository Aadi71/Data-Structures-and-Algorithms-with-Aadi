// https://leetcode.com/problems/water-and-jug-problem/

class Solution {
public:
    bool canMeasureWater(int a, int b, int t) {
        if(a + b == t) return 1;
        if(a + b < t) return 0;
        queue<pair<int, int>> q;
        set<pair<int, int>> s;
        q.push({a, b});
        s.insert({a, b});
        while(!q.empty()){
            pair<int, int> f = q.front();
            q.pop();
            int x = f.first, y = f.second;
            if(x + y == t) return 1;
            int xnew, ynew;
            xnew = x; ynew = b;
            if(s.find({xnew, ynew}) == s.end()){
                q.push({xnew, ynew});
                s.insert({xnew, ynew});
            }
            xnew = a; ynew = y;
            if(s.find({xnew, ynew}) == s.end()){
                q.push({xnew, ynew});
                s.insert({xnew, ynew});
            }
            xnew = 0; ynew = y;
            if(s.find({xnew, ynew}) == s.end()){
                q.push({xnew, ynew});
                s.insert({xnew, ynew});
            }
            xnew = x; ynew = 0;
            if(s.find({xnew, ynew}) == s.end()){
                q.push({xnew, ynew});
                s.insert({xnew, ynew});
            }
            xnew = x - min(x, b - y); ynew = y + min(x, b - y);
            if(s.find({xnew, ynew}) == s.end()){
                q.push({xnew, ynew});
                s.insert({xnew, ynew});
            }
            xnew = x + min(a - x, y); ynew = y - min(a - x, y);
            if(s.find({xnew, ynew}) == s.end()){
                q.push({xnew, ynew});
                s.insert({xnew, ynew});
            }
        }
        return 0;
    }
};
