#include<stdio.h>
#include<stdlib.h>

int g[101][101];
int n, l;

int solve_x(int x){
    int i, j;
    int front = 0;
    
    for(i = 1; i < n; i++){
        if(abs(g[i][x] - g[i + 1][x]) >= 2) return 0;
        
        if(g[i][x] == g[i + 1][x] + 1){
            if(i + l > n) return 0;
            
            for(j = i + 1; j <= i + l; j++){
                if(g[j][x] != g[i][x] - 1) return 0;
            }
            
            front = i + l;
        }else if(g[i][x] == g[i + 1][x] - 1){
            if((i + 1) - l <= 0 || i + 1 - l <= front) return 0;
            
            for(j = i; j >= (i + 1) - l; j--){
                if(g[j][x] != g[i + 1][x] - 1) return 0;
            }
            
            front = i;
        }
    }
    
    return 1;
    
}

int solve_y(int y){
    int i, j;
    int front = 0;

    for(i = 1; i < n; i++){
        if(abs(g[y][i] - g[y][i + 1]) >= 2) return 0;
        
        if(g[y][i] == g[y][i + 1] + 1){
            if(i + l > n) return 0;
            
            for(j = i + 1; j <= i + l; j++){
                if(g[y][j] != g[y][i] - 1) return 0;
            }
            
            front = i + l;
        }else if(g[y][i] == g[y][i + 1] - 1){
            if((i + 1) - l <= 0 || i + 1 - l <= front) return 0;
            
            for(j = i; j >= (i + 1) - l; j--){
                if(g[y][j] != g[y][i + 1] - 1) return 0;
            }
            
            front = i;
        }
    }
    
    return 1;
}

int main(){
    int i, j;
    int answer = 0;
    scanf("%d %d", &n, &l);
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++) scanf("%d", &g[i][j]);
    }
    
    for(i = 1; i <= n; i++){
        if(solve_y(i)) answer++;
    }
    
    for(i = 1; i <= n; i++){
        if(solve_x(i)) answer++;
    } printf("%d", answer);
}