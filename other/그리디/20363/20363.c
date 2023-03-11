#include<stdio.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    
    int ans = 0;
    
    if(x <= y){
        ans = x / 10 + x + y;
    }else{
        ans = y / 10 + y + x;
    } printf("%d", ans);
}