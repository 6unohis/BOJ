#include<stdio.h>

int n, b, w;
char arr[300001];

int max(int n1, int n2){if(n1 <= n2) return n2; else return n1;};

int main(){
    int i, j, left = 0, right = 1;
    scanf("%d %d %d", &n, &b, &w);
    
    scanf("%s", arr);
    int w_cnt = 0, b_cnt = 0;
    
    if(arr[0] == 'W') w_cnt++;
    else b_cnt++;
    
    if(arr[1] == 'W') w_cnt++;
    else b_cnt++;
    int ans = 0;
    while(right < n && left < n && left <= right){
      
        if(b_cnt <= b && w_cnt >= w) ans = max(ans, right - left + 1);
        
        if(b_cnt > b){
            if(arr[left] == 'B') b_cnt--;
            else w_cnt--;
            left++;
        }
        else{
            if(arr[right + 1] == 'B') b_cnt++;
            else w_cnt++;
            right++;
        }
    } 
    
    if(!b){
        w_cnt = 0;
        for(i = 0; i < n; i++){
            if(arr[i] == 'W'){
                w_cnt++;
                if(w_cnt >= w) ans = max(ans, w_cnt);
            }else w_cnt = 0;
        }
    } printf("%d", ans);
}