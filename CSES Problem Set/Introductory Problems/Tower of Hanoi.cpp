#include <bits/stdc++.h>
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define rep(i,a,b) for(int i = a; i < b; i++)
#define vv vector<ll>
#define ll long long

using namespace std;
vector<pair<int, int>> v;
void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod){
    if(n == 0) return;
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    v.push_back(make_pair(from_rod, to_rod));
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    towerOfHanoi(n, 1, 3, 2);
    int s =  v.size();
    cout << s;
    fr(0, s) cout << "\n" << v[i].first << " " << v[i].second;
    return 0;
}
