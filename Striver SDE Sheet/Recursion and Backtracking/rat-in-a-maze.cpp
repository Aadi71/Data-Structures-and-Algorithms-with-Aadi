// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    bool isValid(int i, int j, vector<vector<int>> &m, vector<vector<bool>> &vis){
        if(i >= 0 && j >= 0 && i < m.size() && j < m.size() && m[i][j] == 1 && vis[i][j] == 0) return true;
        return false;
    }
    void solve(vector<vector<int>> &m, vector<vector<bool>> &vis, int i, int j, vector<string> &ans, string temp){
        if(i == m.size() - 1 && j == m.size() - 1){
            ans.push_back(temp);
            return;
        }
        
        int a[] = {0, 0, -1, 1};
        int b[] = {-1, 1, 0, 0};
        char c[] = {'L', 'R', 'U', 'D'};
        
        for(int k = 0; k<4; k++){
            int inew = i + a[k];
            int jnew = j + b[k];
            if(isValid(inew, jnew, m, vis)){
                vis[inew][jnew] = 1;
                temp += c[k];
                solve(m, vis, inew, jnew, ans, temp);
                temp.pop_back();
                vis[inew][jnew] = 0;
            }
        }
    }
  
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0 || m[n - 1][n - 1] == 0) return {};
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool> (n, 0));
        vis[0][0] = 1;
        solve(m, vis, 0, 0, ans, "");
        return ans;
    }
};
