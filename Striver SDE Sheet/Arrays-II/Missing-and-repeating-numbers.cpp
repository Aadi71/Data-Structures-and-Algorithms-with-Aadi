// https://www.codingninjas.com/codestudio/problems/873366

// Brute Force with O(N)-Space Complexity
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	vector<int> v(n + 1, 0);
	for(int i = 0; i<n; i++) v[arr[i]]++;
	int a, b;
	for(int i = 1; i<=n; i++){
		if(v[i] == 2) a = i;
		if(v[i] == 0) b = i; 
	}
	return {b, a};
}

// USing maths formulae concepts and sum of array elements property
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	long long s1 = (n * (n + 1)) / 2;
	long long s2 = (n * (n + 1) * (2*n + 1)) / 6;
	for(int i = 0; i<n; i++){
		s1 -= arr[i];
		s2 -= arr[i] * arr[i];
	}
	int miss = (s1 + s2 / s1) / 2;
	int rep = miss - s1;
	return {miss, rep};
}
