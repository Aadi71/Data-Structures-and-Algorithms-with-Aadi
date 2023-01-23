// https://leetcode.com/problems/find-the-town-judge/

// Brute Force and not good solution.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n + 1, 0);
        for(int i = 0; i<trust.size(); i++) v[trust[i][1]]++;
        vector<int> select;
        for(int i = 1; i<=n; i++) if(v[i] == n - 1) select.push_back(i);
        int ans = -1;
        bool flag = true;
        for(int i = 0; i<select.size(); i++){
            for(int j = 0; j<trust.size(); j++){
                if(trust[j][0] == select[i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true) return select[i];
        }
        return -1;
    }
};

// Optimized Solution
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Judge will be whose (indegree - outdegree = n - 1)
        vector<int> v(n + 1, 0);
        for(int i = 0; i<trust.size(); i++){
            v[trust[i][0]]--;
            v[trust[i][1]]++;
        }
        for(int i = 1; i<=n; i++) if(v[i] == n - 1) return i;
        return -1;
    }
};
