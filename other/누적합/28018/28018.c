#include<stdio.h>

int n, q;
long long arr[1000002];
long long sum[1000002];

int main(){
    int i, j;
    scanf("%d", &n);
    
    while(n--){
        int s, e;
        scanf("%d %d", &s, &e);
        
        arr[s]++;
        arr[e + 1]--;
    }
    
    for(i = 1; i <= 1000000; i++) sum[i] = sum[i - 1] + arr[i];
    
    scanf("%d", &q);
    while(q--){
        int ti;
        scanf("%d", &ti);
        printf("%lld\n", sum[ti]);
    }
}