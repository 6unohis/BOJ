#include<stdio.h>
#include<stdlib.h>

int arr[1000001];
int lis[1000001];
int n;

int bin(int l, int r, int t){
    int m;
    
    while(l < r){
        m = (l + r) / 2;
        if(lis[m] < t) l = m + 1;
        else r = m;
    } return r;
}

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    int ans = 0;
    
    for(i = 0; i < n; i++){
        if(lis[ans] < arr[i]) lis[++ans] = arr[i];
        else{
            int tmp = bin(0, ans, arr[i]);
            lis[tmp] = arr[i];
        }
    }
    
    printf("%d", ans);
}