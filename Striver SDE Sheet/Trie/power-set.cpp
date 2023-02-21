// https://practice.geeksforgeeks.org/problems/power-set4302/1

// Bit Manipulation, TC: O(n * 2^n)
class Solution{
	public:
	vector<string> AllPossibleStrings(string s){
	    vector<string> ans;
	    int n = s.length();
	    for(int i = 0; i < (1 << n); i++){
	        string temp = "";
	        for(int j = 0; j<n; j++){
	            if(i & (1 << j)) temp += s[j];
	        }
	        ans.push_back(temp);
	    }
	    sort(ans.begin(), ans.end());
	    ans.erase(ans.begin()); // Removing empty element or empty string
	    return ans;
	}
};

// Backtracking, TC: O(2^n)
class Solution{
    void solve(string temp, string s, int ind, vector<string> &ans){
        if(ind == s.length()){
            ans.push_back(temp);
            return;
        }
        
        temp += s[ind];
        solve(temp, s, ind + 1, ans);
        temp.pop_back();
        solve(temp, s, ind + 1, ans);
    }
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    solve("", s, 0, ans);
		    sort(ans.begin(), ans.end());
		    ans.erase(ans.begin()); // Removing empty element or empty string
		    return ans;		
		}
};
