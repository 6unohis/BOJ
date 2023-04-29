#include<stdio.h>

int n;
int arr[1000001];
int tmp[1000001];
int min(int a, int b){if(a <= b) return a; else return b;};
int check_asc(){
    int one_cnt = 0, idx;
    int i, j;
    for(i = 1; i <= n; i++){
        if(tmp[i] == 1){
            one_cnt++;
            idx = i;
        }
    }
    
    if(one_cnt == 1) return idx;
    else if(one_cnt == 2){
        if(arr[1] >= arr[n]) return idx;
    }
    
    return 0;
}

int check_desc(){
    int one_cnt = 0, idx;
    int i, j;
    for(i = 1; i <= n; i++){
        if(tmp[i] == 1){
            one_cnt++;
            idx = i;
        }
    }
    
    if(one_cnt == 1) return idx;
    else if(one_cnt == 2){
        if(arr[i] <= arr[n]) return idx;
    }
    
    return 0;
}

int main(){
    int i, j, ans = 987654321;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
    tmp[1] = 1;
    for(i = 2; i <= n; i++){
        if(arr[i] >= arr[i - 1]) tmp[i] = tmp[i - 1] + 1;
        else tmp[i] = 1;
        
    }
    
    int aans = check_asc();
    if(aans) ans = min(aans - 1, ans);
    
    tmp[1] = 1;
    for(i = 2; i <= n; i++){
        if(arr[i] <= arr[i - 1]) tmp[i] = tmp[i - 1] + 1;
        else tmp[i] = 1;
    }
    
    aans = check_desc();
    if(aans) ans = min(aans - 1, ans);
    
    if(ans == 987654321) printf("-1");
    else printf("%d", ans);
}