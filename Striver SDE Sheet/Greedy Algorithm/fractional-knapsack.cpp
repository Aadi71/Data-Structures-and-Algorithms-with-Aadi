// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

bool cmp(Item a, Item b){
    return a.value*b.weight>b.value*a.weight;
}
class Solution{
    public:
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr + n, cmp);
        double ans = 0;
        for(int i = 0; i<n; i++){
            if(W >= arr[i].weight){
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else{
                ans += (arr[i].value * 1.0 / arr[i].weight) * W;
                break;
            }
        }
        return ans;
    }
};
