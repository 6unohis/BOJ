#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000000

int NoPrime[SIZE + 1];
int n;

int main(){
    int i, j;
    scanf("%d", &n);
    
    NoPrime[1] = 1;
    for(i = 2; i <= SIZE; i++){
        if(NoPrime[i]) continue;
        else{
            for(j = i + i; j <= SIZE; j+=i) NoPrime[j] = 1;
        }
    }
    
    for(i = n; i <= SIZE; i++){
        if(!NoPrime[i]){
            int tmp[10];
            int _tmp = i;
            int rear = 0;
            int front = 0;
            int state = 1;
            
            while(_tmp){
                tmp[rear++] = _tmp % 10;
                _tmp/=10;
            } rear--;
            
            while(front < rear){
                if(tmp[front++] != tmp[rear--]){
                    state = 0;
                    break;
                }
            }
            
            if(state){
                printf("%d", i);
                exit(0);
            }
            else continue;
        }
    }
    printf("1003001");
}