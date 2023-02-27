#include<stdio.h>

long long x, y, w, s;

int main(){
    scanf("%lld %lld %lld %lld", &x, &y, &w, &s);
    long long answer;
    int cross;
    if(x <= y) cross = x;
    else cross = y;
    
    if(w * 2 < s){
        answer = w*(x + y);
    }else{
        x -= cross;
        y -= cross;
        answer = cross * s;
        
        if(w < s){
            if(y) answer += y * w;
            else answer += x * w;
        }
        else{
            if(y){
                if(y % 2 == 0) answer += y * s;
                else{
                    answer += (y - 1) * s + w;
                }
            }else{
                if(x % 2 == 0) answer += x * s;
                else{
                    answer += (x - 1) * s + w;
                }
            }
        }
    } printf("%lld", answer);
}