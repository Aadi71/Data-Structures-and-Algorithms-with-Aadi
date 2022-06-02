#include <iostream>
using namespace std;

// Problem 1: https://www.codechef.com/START41D/problems/CBSPEED

int main() {
	// your code goes here
	
	int a, b;
	cin>>a>>b;
	
	if(a<b) cout<<"YES";
	else cout<<"NO";
	return 0;
}

// Problem 2: https://www.codechef.com/START41D/problems/CCHOCOLATES

int main() {
	int n;
	cin>>n;
	
	while(n--){
	    int x, y, z;
	    cin>>x>>y>>z;
	    
	    int sum = x*5 + y*10;
	    cout<<sum/z<<"\n";
	}
	return 0;
}



// Problem 3: https://www.codechef.com/START41D/problems/WINNERR
int main() {
	int n;
	cin>>n;
	
	while(n--){
	    int pa, pb, qa, qb;
	    cin>>pa>>pb>>qa>>qb;
	    
	    int p = pa > pb ? pa : pb;
	    int q = qa > qb ? qa : qb;
	    
	    if(p>q) cout<<"Q";
	    else if(p<q) cout<<"P";
	    else cout<<"TIE";
	    
	    cout<<"\n";
	}
	return 0;
}


// Problem 4: https://www.codechef.com/START41D/problems/INCREAR

int main() {
	int n;
	cin>>n;
	
	while(n--){
	    int a, b;
	    cin>>a>>b;
	    
	    int sum = 0;
	    if(a == b){
            cout<<sum<<"\n";
        }
        else{
            if(a > b && (a - b) % 2 == 0) sum = (a - b) / 2;

            else if(a > b) sum = (a - b) / 2 + 2;

            else sum = (b - a); 
            
            cout<<sum<<"\n";
        }
        
            
	}
	return 0;
}


// Problem 5: https://www.codechef.com/START41D/problems/PATHPAR

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    
	    if(n%2 == 0 || (n%2 == 1 && k == 1)) cout<<"YES";
	    else cout<<"NO";
	    cout<<"\n";
	}
	return 0;
}


// Problem 6: https://www.codechef.com/START41D/problems/ISPAR

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    long long n, k;
	    cin>>n>>k;
	    
	    if(k == 1 && (n&1) || k == 2)
	        cout<<"ODD";
	    else cout<<"EVEN";
	    cout<<"\n";
	}
	
	return 0;
}

// Problem 7: https://www.codechef.com/START41D/problems/ISPAR

// Problem 8: https://www.codechef.com/START41D/problems/DEARRANGE

