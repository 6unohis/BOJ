#include<stdio.h>
#define ll long long

int n, q;
int arr[100001];
ll sum[100001];
ll fun[100001];

int main(){
    int i, j;
    scanf("%d %d", &n, &q);
    
    for(i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
        
        fun[i] = fun[i - 1] + (sum[i - 1] * arr[i]);
    }
    
    while(q--){
        int l, r;
        scanf("%d %d",  &l, &r);
        
        ll gap = fun[r] - fun[l - 1];
        printf("%lld\n", gap - sum[l - 1] * (sum[r] - sum[l - 1]));
    }
}