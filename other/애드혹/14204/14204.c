#include<stdio.h>

int n, m;
int g[51][51];

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++) scanf("%d", &g[i][j]);
    }
    
    int arr[51];
    int t;
    
    for(j = 1; j <= m; j++){
        arr[j] = g[1][j] % m;
        
        if(j == 1){
            t = (g[1][j] - 1) / m;
        }else{
            if((g[1][j] - 1) / m != t){
                printf("0");
                return 0;
            }  
        }
    }
    
    for(i = 2; i <= n; i++){
        int tmp[51];
        for(j = 1; j <= m; j++){
            tmp[j] = g[i][j] % m;
            
            if(tmp[j] != arr[j]){
                printf("0");
                return 0;
            }
            
            if(j == 1) t = (g[i][j] - 1) / m;
            else{
                if((g[i][j] - 1) / m != t){
                    printf("0");
                    return 0;
                }
            }
        }
    }
    
    printf("1");
}