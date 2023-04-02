#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    int e1 = *(int*)a;
    int e2 = *(int*)b;
    
    if(e1 < e2) return -1;
    else if(e1 > e2) return 1;
    else return 0;
}

int n;

int main(){
    int i, j;
    scanf("%d", &n);
    int arr[n];
    int tmp[n];
    
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(i = 0; i < n; i++) scanf("%d", &tmp[i]);
    
    qsort(arr, n, sizeof(int), compare);
    qsort(tmp, n, sizeof(int), compare);
    
    int cnt = 0;
    int left = 0;
    int right = 0;
    
    for(i = 0; i < n; i++){
        if(tmp[i] > arr[left]){
            right = i;
            break;
        }
    }
    
    while(left < n && right < n){
        if(arr[left] < tmp[right]){
            cnt++;
            left++;
            right++;
        }else right++;
    }
    
    if(cnt >= (n + 1) / 2) printf("YES");
    else printf("NO");
}