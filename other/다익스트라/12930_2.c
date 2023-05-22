#include<stdio.h>

int dp[21][255][255];
int dist[22];
char g[21][21];
int w1[21][21];
int w2[21][21];
int n, res = 987654321;

void solve(int idx, int _w1, int _w2){
    int i, j;
    
    for(j = 0; j < n; j++){
        if(w1[idx][j] && w2[idx][j]){
            int dist1 = _w1 + w1[idx][j];
            int dist2 = _w2 + w2[idx][j];
            dp[j][dist1][dist2] = 1;
            
            if(dist[j] > dist1 * dist2){
                dist[j] = dist1 * dist2;
                solve(j, dist1, dist2);
            }
        }
    }
}

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) scanf("%s", g[i]);
    for(i = 0; i < n; i++){
        dist[i] = res;
        for(j = 0; j < n; j++){
            if(g[i][j] >= '1' && g[i][j] <= '9') w1[i][j] = g[i][j] - '0';
        }
    }
    
    for(i = 0; i < n; i++) scanf("%s", g[i]);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(g[i][j] >= '1' && g[i][j] <= '9') w2[i][j] = g[i][j] - '0';
        }
    }
        
    dp[0][0][0] = 1;
    dist[0] = 0;
    solve(0, 0, 0);
    
    if(dist[1] == 987654321) printf("-1");
    else printf("%d", dist[1]);
}
