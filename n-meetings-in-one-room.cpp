// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), sortcol);
        int c = 0;
        int et = v[0][1];
        for(int i = 1; i<n; i++){
            
            if(v[i][0] > et){
                c++;
                et = v[i][1];
            }
        }
        return ++c;
    }
};
