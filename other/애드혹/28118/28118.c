#include<stdio.h>
int g[51][51];
int v[51];
int n, m;

void go(int idx){
    int i, j;
    v[idx] = 1;
    
    for(j = 1; j <= n; j++){
        if(g[idx][j] && !v[j]) go(j);
    }
}

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    
    while(m--){
        int s, t;
        scanf("%d %d", &s, &t);
        g[s][t] = 1;
        g[t][s] = 1;
    }
    
    int ans = 0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(!v[i]){
                go(i);
                ans++;
            }
        }
    } printf("%d", ans - 1);
}