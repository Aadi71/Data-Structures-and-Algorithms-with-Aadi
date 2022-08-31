#include <bits/stdc++.h>
using namespace std;

struct Time{
    int start;
    int end;
};

bool comp(Time a, Time b){
    return a.end < b.end;
}

int solve(vector<Time> &v, int n){
    sort(v.begin(), v.end(), comp);
    int res = 0;
    int endTime = -1;
    for(int i = 0; i<n; i++){
        if(v[i].start >= endTime){
            res++;
            endTime = v[i].end;
        }
    }
    return res;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    Time t;
    vector<Time> v;
    for(int i = 0; i<n; i++){
        int s, e;
        cin >> s >> e;
        t.start = s;
        t.end = e;
        v.push_back(t);
    }
    cout << solve(v, n);
}
