#include<stdio.h>

int idx[11];
int n, s, r;

int nex[2] = {-1, 1};

int main(){
    int i, j;
    int answer = 0;
    scanf("%d %d %d", &n, &s, &r);
    
    while(s--){
        int a;
        scanf("%d", &a);
        
        idx[a] = -1;
    }
    
    while(r--){
        int a;
        scanf("%d", &a);
        
        idx[a]++;
    }
    
    for(i = 1; i <= n; i++){
        if(idx[i] != 1) continue;
        
        int next;
        for(j = 0; j < 2; j++){
            next = i + nex[j];
            
            if(next <= 0 || next > n) continue;
            
            if(idx[next] == -1 && idx[i] == 1){
                idx[next]++;
                idx[i]--;
            }
        }
    }
    
    for(i = 1; i <= n; i++){
        if(idx[i] < 0) answer++;
    }printf("%d", answer);
}