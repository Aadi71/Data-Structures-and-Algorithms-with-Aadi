#include <bits/stdc++.h>
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define rep(i,a,b) for(int i = a; i < b; i++)
 
#define ll long long
 
using namespace std;
int maxDigit(int n){
    ll m = LLONG_MIN;
    while(n > 0){
        ll r = n % 10;
        m = max(r, m);
        n = n / 10;
    }
    return m;
}
int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> nums(n+1, 0);
    fr(0, 10) nums[i] = 1;
    fr(10, n + 1)
        nums[i] += 1 + nums[i - maxDigit(i)];
    cout << nums[n] << "\n";
}
