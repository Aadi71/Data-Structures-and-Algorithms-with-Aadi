#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll ans = 0;
    for(int i = 5; n / i>=1; i*=5)
        ans += n / i;
    cout << ans;
}
