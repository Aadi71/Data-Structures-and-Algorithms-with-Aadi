#include <bits/stdc++.h>
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define rep(i,a,b) for(int i = a; i < b; i++)
#define vv vector<ll>
#define ll long long

using namespace std;

int main(){
    ll n; cin >> n;
    vv v(n, 0);
    fr(0, n) cin >> v[i];
    set<int> s;
    ll i = 0, j = 0, ans = 0;
    while(i < n && j < n){
        while(j < n && !s.count(v[j])){
            s.insert(v[j]);
            ans = max(ans, j - i + 1);
            j++;
        }
        while(j < n && s.count(v[j])){
            s.erase(v[i]);
            i++;
        }
    }
    cout << ans;
}
