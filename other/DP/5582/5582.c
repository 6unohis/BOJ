#include<stdio.h>
#include<string.h>

int dp[4001][4001];
char str1[4001];
char str2[4001];

int max(int a, int b){if(a <= b) return b; else return a;};

int main(){
    int i, j;
    scanf("%s", str1);
    scanf("%s", str2);
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int ans = 0;
    
    for(i = 1; i <= len1; i++){
        for(j = 1; j <= len2; j++){
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            
            ans = max(ans, dp[i][j]);
        }
    } printf("%d", ans);
}