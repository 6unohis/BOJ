#include<stdio.h>

int tmp[10000];
int arr[41];
int n, m;

int main(){
    scanf("%d %d", &n, &m);
    int i, j;
    
    for(i = 1; i <= m; i++){
        int a;
        scanf("%d", &a);
        arr[a] = 1;
    }
    
    tmp[0] = 1;
    tmp[1] = 2;
    
    for(i = 2; i <= 40; i++) tmp[i] = tmp[i - 1] + tmp[i - 2];

    int front = 1;
    int ans = 1;
    for(i = 1; i <= n; i++){
        if(arr[i] == 1){
          if(tmp[i - front - 1])  ans *= tmp[(i - front - 1)];
          front = i + 1;
        }
    }
    
    if(arr[n] != 1){
        ans *= tmp[(n - front)];
    }
    printf("%d", ans);
}