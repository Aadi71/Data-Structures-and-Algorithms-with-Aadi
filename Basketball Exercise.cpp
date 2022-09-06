// https://codeforces.com/contest/1195/problem/C

#include<bits/stdc++.h>
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define vv vector<int>
using namespace std;


int main(){
    int n; cin >> n;
    vv first(n, 0);
    vv second(n, 0);
    fr(0, n){
        cin >> first[i]; 
    }
    fr(0, n){
        cin >> second[i]; 
    }
    vector<pair<int, int>> v;
    v.push_back(make_pair(first[0], second[0]));

    fr(1, n){
        int a = v[i - 1].first > (v[i - 1].second + first[i]) ?  v[i - 1].first : (v[i - 1].second + first[i]);
        int b = v[i - 1].second > (v[i - 1].first + second[i]) ?  v[i - 1].second : (v[i - 1].first + second[i]);
        v.push_back(make_pair(a, b));
    }
    if(v[n - 1].first > v[n - 1].second) cout << v[n - 1].first;
    else cout << v[n - 1].second;
    return 0;
}
