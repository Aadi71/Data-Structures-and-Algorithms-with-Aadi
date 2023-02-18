// https://leetcode.com/problems/permutation-sequence/

// Brute Force. Giving TLE. TC: O(N!) + O(NlogN)
class Solution {
public:
    void solve(int ind, vector<string> &v, string s){
        if(ind == s.length()){
            v.push_back(s);
            return;
        }
        for(int i = ind; i<s.size(); i++){
            swap(s[ind], s[i]);
            solve(ind + 1, v, s);
            swap(s[ind], s[i]);
        }  
    }

    string getPermutation(int n, int k) {
        if(n == 0) return "";  
        string s = "";
        for(int i = 1; i<=n; i++) s += to_string(i);
        vector<string> v;
        solve(0, v, s);
        sort(v.begin(), v.end());
        return v[k - 1];

    }
};


// Optimized Solution with TC: O(N)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> v;
        for(int i = 1; i<n; i++){
            fact *= i;
            v.push_back(i);
        }
        v.push_back(n);
        string ans = "";
        k--;
        while(v.size()){
            ans += to_string(v[k / fact]);
            v.erase(v.begin() + k / fact);
            k %= fact;
            if(v.size() != 0) fact /= v.size();
        }   
        return ans;
    }
};
