// https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int count = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n; i++){
                string node = q.front();
                q.pop();
                if(node == end) return count;
                for(char c: "AGCT"){
                    for(int j = 0; j<8; j++){
                        string temp = node;
                        temp[j] = c;
                        if(!visited.count(temp) && find(bank.begin(), bank.end(), temp) != bank.end()){
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
