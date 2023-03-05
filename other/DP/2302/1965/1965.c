#include<stdio.h>

int arr[1001];
int dp[1001];

int max(int a, int b){if(a <= b) return b; else return a;};

int main(){
    int i, j;
    int n;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        dp[i] = 1;
    }
    
    int ans = 0;
    
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            if(arr[i] < arr[j]) dp[j] = max(dp[j], dp[i] + 1);
            
            
        }ans = max(dp[i], ans);
    }
    
    printf("%d", ans);
}