#include <bits/stdc++.h>
#define fr(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vv vector<ll>
#define ll long long
#define mod 1000000007

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll n; cin >> n;
	vector<string> v(n,"");

	fr(0,n){
		cin >> v[i];
	}

	if(v[n - 1][n - 1] == '*' || v[0][0] == '*'){
		cout << 0;
		return 0;
	}

	ll dp[n + 1][n + 1];
	for(ll i = n; i>= 1; i--){
		for(ll j = n; j>= 1; j--){
			if(v[i - 1][j - 1] == '*') dp[i][j] = 0;
			else if(i == n && j == n) dp[i][j] = 1;
			else{
				ll a = (j == n) ? 0 : dp[i][j + 1];
				ll b = (i == n) ? 0 : dp[i + 1][j];
				dp[i][j] = (a + b) % mod;
			}
		}	
	}

	cout << dp[1][1];

	return 0;
}
