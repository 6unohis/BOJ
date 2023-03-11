#include<stdio.h>
#include<stdlib.h>

int n;
int arr[1000001];
int tmp[1000001];

int main(){
    int i, j;
    scanf("%d", &n);
    
    int start_idx;
    int end_idx;
    
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    int start_num = arr[0];
    int end_num = arr[n - 1];
    
    for(i = 0; i < n; i++){
        scanf("%d", &tmp[i]);
        if(tmp[i] == start_num) start_idx = i;
        if(tmp[i] == end_num) end_idx = i;
    }
    
    int next;
        
    if(start_idx < end_idx){
        if(abs(start_idx - end_idx) == 1){
            for(i = 0; i < n; i++){
                if(start_idx - i < 0) next = start_idx - i + n;
                else next = start_idx - i;
                
                if(tmp[next] != arr[i]){
                    
                    printf("bad puzzle");
                    return 0;
                }
            }
        }else{
            for(i = 0; i < n; i++){
                if(tmp[i] != arr[i]){
                    
                    printf("bad puzzle");
                    return 0;
                }
            }
        }
    }else{
        if(abs(start_idx - end_idx) == 1){
            for(i = 0; i < n; i++){
                next = (start_idx + i) % n;
                
                if(tmp[next] != arr[i]){
                   
                    printf("bad puzzle");
                    return 0;
                }
            }
        }else{
            for(i = 0; i < n; i++){
                next = start_idx - i;
                if(tmp[next] != arr[i]){
                    printf("bad puzzle");
                    return 0;
                }
            }
        }
    } printf("good puzzle");
}