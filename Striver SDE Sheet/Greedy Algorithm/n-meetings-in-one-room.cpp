// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

lass Solution
{
    public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n){
        if(n == 0) return 0;
        vector<pair<int, int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), cmp);
        int sum = 1;
        int e = v[0].second;
        for(int i = 1; i<n; i++){
            if(v[i].first > e){
                sum++;
                e = v[i].second;
            }
        }
        return sum;
    }
};
