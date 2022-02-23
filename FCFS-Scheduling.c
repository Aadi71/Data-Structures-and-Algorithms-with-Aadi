#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    printf("Process Burst Time Waiting Time Turnaround Time\n");
    int arr[n];
    for(int i = 0;i<n;i++) scanf("%d", &arr[i]);
    int wt = 0;
    int tt = 0;
    
    float awt = 0;
    float att = 0;
    for(int i = 1; i<=n;i++){
        tt+= arr[i-1];
        att+= tt;
        printf("p%d %d %d %d\n",i,arr[i-1], wt, tt);
        wt+= arr[i-1];
        awt+=wt;
    }
    awt -= wt;
    printf("Average Waiting Time=%f\nAverage Turnaround Time=%f", awt/n, att/n);
    
}
