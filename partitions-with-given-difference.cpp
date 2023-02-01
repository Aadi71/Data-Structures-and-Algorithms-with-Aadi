// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i<n; i++) sum += arr[i];
    if((sum - d) % 2 || sum - d < 0) return 0;
    int t = (sum - d)/2;
    vector<int> prev(t + 1, 0), curr(t + 1, 0);
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(arr[0] != 0 && arr[0] <= t) prev[arr[0]] = 1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=t; j++){
            int notTake = prev[j];
            int take = 0;
            if(arr[i] <= j) take = prev[j - arr[i]];
            curr[j] = (take + notTake) % 1000000007; 
        }
        prev = curr;
    }
    return prev[t];
}


