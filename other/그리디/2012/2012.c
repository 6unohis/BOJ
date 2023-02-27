#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    int elem1 = *(int*)a;
    int elem2 = *(int*)b;
    
    if(elem1 < elem2) return -1;
    else if(elem1 > elem2) return 1;
    else return 0;
}

int main(){
    int n, i;
    scanf("%d", &n);
    
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    qsort(arr, n, sizeof(int), compare);
    long long answer = 0;
    for(i = 0; i < n; i++){
        answer += abs(i + 1 - arr[i]);
    } printf("%lld", answer);
}