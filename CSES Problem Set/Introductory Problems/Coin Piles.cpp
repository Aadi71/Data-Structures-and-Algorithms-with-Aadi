#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    while(n--){
        int a, b; cin >> a>> b;
        if((a + b) % 3 != 0 || a > 2 * b || b > 2 * a) cout << "NO\n";
        else cout << "YES\n";
    }
}
