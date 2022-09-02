#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll mid = v[v.size()/2];
    ll diff = 0;
    for(ll i = 0; i<n; i++) diff += abs(mid - v[i]);
    cout << diff;
}
