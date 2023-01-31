// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?

int minSubsetSumDifference(vector<int>& arr, int n){
	int sum = 0;
	for(int i = 0; i<n; i++) sum += arr[i];
	int t = sum / 2;
	vector<bool> prev(t + 1, 0), curr(t + 1, 0);
	prev[0] = 1; curr[0] = 1;
	if(arr[0] <= t) prev[arr[0]] = 1;
	for(int i = 1; i<n; i++){
		for(int j = 1; j<=t; j++){
			bool notTake = prev[j];
			bool take = false;
			if(arr[i] <= j) take = prev[j - arr[i]];
			curr[j] = take | notTake;
		}
		prev = curr;
	}

	int ans = INT_MAX;
	for(int i = 0; i<=t; i++) if (prev[i] == 1) ans = min(ans, abs((sum - i) - i));
	return ans;
}
