// https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1
// T.C: O(N)
// A.S: O(N)

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        unordered_map<int, int> map;
        for(int i = 0; i<N; i++) map[A[i]]++;
        
        for(int i = 0; i<N; i++){
            if(map.find(B[i]) == map.end()) return false;
            if(map[B[i]] == 0) return false;
            map[B[i]]--;
        }
        return true;
    }
};
