// https://www.codingninjas.com/codestudio/problems/1062679?

#include <bits/stdc++.h> 
using namespace std;
double mul(double num, int n){
	double ans = 1.0;
	for(int i = 0; i<n; i++) ans *= num;
	return ans;
}

double findNthRootOfM(int n, int m) {
	double l = 1;
	double h = m;
	double d = 1e-7;

	while(h - l > d){
		double mid = (l + h)/2.0;
		if(mul(mid, n) > m) h = mid;
		else l = mid; 
	}
	return l;
}
