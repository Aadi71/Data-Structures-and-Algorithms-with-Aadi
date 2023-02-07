// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

bool cmp(Job a, Job b){
    if(a.profit == b.profit) return a.dead > b.dead;
    return a.profit > b.profit;
}

class Solution {
    public:
    vector<int> JobScheduling(Job arr[], int n){ 
        sort(arr, arr + n, cmp);
        int maxi = 1;
        for(int i = 0; i<n; i++) maxi = max(maxi, arr[i].dead);
        int max_pro = 0;
        vector<int> v(maxi + 1, -1);
        int freq = 0;
        for(int i = 0; i<n; i++){
            for(int j = arr[i].dead; j>0; j--){
                if(v[j] == -1){
                    max_pro += arr[i].profit;
                    freq++;
                    v[j] = i;
                    break;
                }
            }
        }
        return {freq, max_pro}; 
    } 
};
