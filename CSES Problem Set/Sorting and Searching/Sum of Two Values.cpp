#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin >> n >> x;
    vector<pair<int, int>>v;
    for(int i = 0; i<n; i++){
        int num; cin >> num;
        v.push_back(make_pair(num, i + 1));
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while(i < j){
        if(v[i].first + v[j].first == x){
            cout << v[i].second << " " << v[j].second;
            break; 
        }
        else if(v[i].first + v[j].first > x) j--;
        else i++;
    }
    if(i >= j) cout <<"IMPOSSIBLE";
    
}
