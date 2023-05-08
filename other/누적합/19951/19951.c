#include<stdio.h>

int n, m;
int arr[100001];
int tmp[100002];
int sum[100001];

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    
    for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
    while(m--){
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        
        tmp[a] += k;
        tmp[b + 1] += k * -1;
    }
    
    for(i = 1; i <= n; i++) sum[i] = sum[i - 1] + tmp[i];
    
    for(i = 1; i <= n; i++) printf("%d ", arr[i] + sum[i]);
}