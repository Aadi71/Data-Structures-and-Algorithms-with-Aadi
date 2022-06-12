// https://www.codechef.com/JUNE221D/problems/EQUALSTRING

#include <iostream>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    string a, b;
	    cin>>a>>b;
	    int sum = 0;
	    
	    int c[26] = {0};
	    for(int i = 0; i<n; i++){
	        if(a[i] != b[i]){
	            c[b[i] - 97]++;
	        }
	    }
	    
	    int final = 0;
	    for(int i = 0; i<26; i++){
	        if(c[i] > 0) final++;
	    }
	    
	    cout<<final <<"\n";
	}
	return 0;
}
