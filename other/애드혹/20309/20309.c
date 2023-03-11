#include<stdio.h>
#include<stdlib.h>

int n;
int arr[300001];
int idx[300001];

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        idx[i] = abs(i - arr[i]);
    }
    
    for(i = 1; i <= n; i++){
        if(idx[i] % 2 != 0){
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    
}