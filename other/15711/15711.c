#include<stdio.h>
#define SIZE 2000000
int t;
int Prime[SIZE + 1]; // 0 -> prime
int list[SIZE];
int rear = 1;

int main(){
    int i, j;
    scanf("%d", &t);
    
    Prime[1] = 1;
    for(i = 2; i <= SIZE; i++){
        if(Prime[i] == 1) continue;
        else{
            list[rear++] = i;
            for(j = i + i; j <= SIZE; j+=i) Prime[j] = 1;
        }
    }
    
    while(t--){
        int state = 1;
        long long a, b;
        scanf("%lld %lld", &a, &b);
        
        long long tmp = a + b;
        if(tmp % 2 == 0){
            if(tmp == 2) printf("NO\n");
            else printf("YES\n");
        }else{
            tmp -= 2;
            if(tmp <= SIZE){
                if(Prime[tmp]) state = 0;
            }else{
                for(i = 1; i < rear; i++){
                    if(tmp % list[i] == 0){
                        state = 0;
                        break;
                    }
                }
            }
            
            if(state) printf("YES\n");
            else printf("NO\n");
        }
    }
}