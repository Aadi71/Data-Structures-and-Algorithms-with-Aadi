// https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(), deadends.end());
        if(dds.find("0000") != dds.end() || dds.find(target) != dds.end()) return -1;
        queue<string> q;
        unordered_set<string> uset;
        q.push("0000");
        uset.insert("0000");
        int lvl = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string s = q.front();
                if(s == target) return lvl;
                q.pop();
                for(int i = 0; i<4; i++){
                    string temp = s;
                    temp[i] = (s[i] - '0' + 1) % 10 + '0';
                    if(uset.find(temp) == uset.end() && dds.find(temp) == dds.end()){
                        q.push(temp);
                        uset.insert(temp);
                    }
                    temp[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
                    if(uset.find(temp) == uset.end() && dds.find(temp) == dds.end()){
                        q.push(temp);
                        uset.insert(temp);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
