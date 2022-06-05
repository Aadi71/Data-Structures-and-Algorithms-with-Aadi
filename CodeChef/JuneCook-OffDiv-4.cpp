#include <iostream>
using namespace std;

// https://www.codechef.com/COOK142D/problems/ADVANCE

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int x, y; cin>>x>>y;
	    
	    if(y<= x+200 && y>=x) cout<<"YES";
	    else cout<<"NO";
	    cout<<"\n";
	}
	return 0;
}

// https://www.codechef.com/COOK142D/problems/SONGS

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n, x; cin>>n>>x;
	    
	    x = x * 3;
	    cout<<n/x<<"\n";
	}
	return 0;
}

// https://www.codechef.com/COOK142D/problems/FIRSTANDLAST

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n; i++) cin>>arr[i];
	    int sum = 0;
	    int m = arr[0] + arr[n-1];
	    for(int i = 0; i<n-1; i++){
	        sum = arr[i] + arr[i+1];
	        m = max(m, sum); 
	    }
	    cout<<m<<"\n";
	}
	return 0;
}

// https://www.codechef.com/COOK142D/problems/BREAKSTICK

int sticks(int n, int x){
    if(n % 2 != 0){
        if(x % 2 == 0) return 0;
        else return 1;
    }
    else{
        return 1;
    }
    
}


int main() {
	int t; cin>>t;
	while(t--){
	    int n, x; cin>>n>>x;
	    int ans = sticks(n, x);
	    if(ans) cout<<"YES"<<"\n";
	    else cout<<"NO"<<"\n";
	}
	return 0;
}

// https://www.codechef.com/COOK142D/problems/SIMPLE_XOR

int main() {
	int t; cin>>t;
	while(t--){
	    int l, r; cin>>l>>r;
	    if(l % 2 == 0){
	        if(l+3 <= r) cout<<l<<" "<<l+1<<" "<<l+2<<" "<<l+3<<"\n";
	        else cout<<-1<<"\n";
	    }
	    else{
	        if(l + 4 <= r) cout<<l+1<<" "<<l+2<<" "<<l+3<<" "<<l+4<<"\n";
	        else cout<<-1<<"\n";
	    }
	    
	}
	return 0;
}