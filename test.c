#include<stdio.h>
#include<string.h>

char arr[5001];
int dp[5001];

int main(){
    int i;
    
    scanf("%s", arr);
    int len = strlen(arr);
    
    dp[len] = 1;
    dp[len - 1] = 1;
    for(i = len - 2; i >= 0; i--){
        int num = arr[i] - '0';
        if(num <= 2 && num >= 1 && arr[i + 1] - '0' <= 6) dp[i] = dp[i + 1] + dp[i + 2];
        else dp[i] = dp[i + 1];
    }
    
    printf("%d", dp[0]);
}