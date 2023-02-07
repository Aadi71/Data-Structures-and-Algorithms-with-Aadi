// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n){
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int maxi = 1;
    	int ans = 1;
    	int i = 1, j = 0;
    	
    	while(i < n){
    	    if(arr[i] > dep[j]){
    	        j++;
    	        maxi--;
    	    }
    	    else if(arr[i] <= dep[j]){
    	        maxi++;
    	        i++;
    	    }
    	    ans = max(maxi, ans);
    	}
    	return ans;
    }
};
