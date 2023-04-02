#include<stdio.h>

int n;
int arr[100001];
int dp[3][100001];

int max(int a, int b){if(a<=b) return b; else return a;};

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
    
    int ans = 0;
    
    for(i = 1; i <= 2; i++){
        for(j = 1; j <= n; j++){
            if(arr[j] == i) dp[i][j] = dp[i][j - 1] + 1;
            else{
                if(dp[i][j - 1] == 0) dp[i][j] = 0;
                else dp[i][j] = dp[i][j - 1] - 1;
            } ans = max(ans, dp[i][j]);
        }
    }
    
    printf("%d", ans);
}