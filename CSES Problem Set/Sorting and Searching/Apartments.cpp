#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(vector<int> &a, vector<int> &b, int k){
    int i = 0, j = 0;
    int count = 0;
    int as = a.size();
    int bs = b.size();
    while(i < as && j < bs){
        if(abs(a[i] - b[j]) <= k){
            i++; j++;
            count++;
        }
        else{
            if(a[i] > b[j]) j++;
            else i++;
        }
    }
    return count;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n, 0);
    for(int i = 0; i <n; i++) cin >> a[i];

    vector<int> b(m, 0);
    for(int i = 0; i<m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << solve(a, b, k) << " ";
}
