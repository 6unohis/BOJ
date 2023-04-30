#include<stdio.h>

int n;
int arr[2001];
int dp[2001][2001];

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        dp[i][i] = 1;
    }
    
    for(i = 1; i < n; i++){
        if(arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
    }
    
    for(j = 3; j <= n; j++){
        int k = j;
        i = 1;
        while(k <= n){
            if(arr[k] == arr[i] && dp[i + 1][k - 1]) dp[i][k] = 1;
            k++;
            i++;
        }
    }
    
    int order;
    scanf("%d", &order);
    
    while(order--){
        int s, t;
        scanf("%d %d", &s, &t);
        printf("%d\n", dp[s][t]);
    }
}