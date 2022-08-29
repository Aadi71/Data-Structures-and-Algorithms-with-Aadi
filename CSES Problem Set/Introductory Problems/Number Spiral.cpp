#include <iostream>
#include <set>
using namespace std;
 
typedef long long ll;
 
ll solve(ll x, ll y){
    ll l = x > y ? x - 1 : y - 1;
    if(l & 1){
        if(x < y) return l*l + x;
        else return l * l + 2 * l - y + 2;
    } else {
        if(x < y) return l * l + 2 * l - x + 2;
        else return l * l + y;
    }
}
 
int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    while(n--){
        ll r, c;
        cin >> r >> c;
        cout << solve(r, c) << "\n";
    }
}
