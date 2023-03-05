#include<stdio.h>

int dp[201];
int arr[201];
int n;

int max(int a, int b){if(a <= b) return b; else return a;};

int main(){
    int i, j;
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        dp[i] = 1;
    }

    int tmp = 0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(arr[i] < arr[j]) dp[j] = max(dp[j], dp[i] + 1);
        }

        tmp = max(tmp, dp[i]);
    }

    printf("%d", n - tmp);
}