// https://leetcode.com/problems/find-unique-binary-string/

// Naiva Approach: Time Limit Exceeded
class Solution {
  public:
    vector<string> res;
    void add_seq(vector<char>& nums) {
        string s = "";
        for(auto itr: nums) s += itr;
        res.push_back(s);
    }

    void generate_sequences(vector<char> all_nums, int i, int n) {
        if (i == n) {add_seq(all_nums); return;}

        all_nums[i] = '0';
        generate_sequences(all_nums, i + 1, n);
        all_nums[i] = '1';
        generate_sequences(all_nums, i + 1, n);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<char> all_nums(n, '0');
        generate_sequences(all_nums, 0, n);

        for(auto itr: res) 
            if (find(nums.begin(), nums.end(), itr) == nums.end()) 
                return itr;
        return "";
    }  
};


// Optimized apporach - Cantor's Diagonal Argument

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        for(int i = 0; i < nums.size(); i++){
            res += nums[i][i] == '0' ? '1' : '0';
        }
        return res;
    }
};
