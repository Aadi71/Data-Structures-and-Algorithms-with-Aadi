#include <bits/stdc++.h>
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define rep(i,a,b) for(int i = a; i < b; i++)
#define vv vector<ll>
#define ll long long

using namespace std;

void permutations(string s, string l, vector<string> &res){
    if(s.length() < 1)res.push_back(l + s);
    unordered_set<char> uset;
    fr(0, s.length()){
        if(uset.find(s[i]) != uset.end()) continue;
        else uset.insert(s[i]);
        string temp = "";
        if(i < s.length() - 1) temp = s.substr(0, i) + s.substr(i + 1);
        else temp = s.substr(0, i);
        permutations(temp, l + s[i], res); 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string> res;
    permutations(s, "", res);
    cout << res.size();
    fr(0, res.size()) cout << "\n" << res[i];
    return 0;
}
