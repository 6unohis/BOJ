#include<stdio.h>

int mindp[4];
int maxdp[4];
int n;

int max(int a, int b){if(a <= b) return b; else return a;};
int min(int a, int b){if(a <= b) return a; else return b;};

int main(){
    int i, j;
    scanf("%d", &n);
    
    scanf("%d %d %d", &maxdp[1], &maxdp[2], &maxdp[3]);
    mindp[1] = maxdp[1]; mindp[2] = maxdp[2]; mindp[3] = maxdp[3];
    
    for(i = 2; i <= n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int tmp1, tmp2, tmp3;
        tmp1 = max(maxdp[1], maxdp[2]) + a;
        tmp2 = max(max(maxdp[1], maxdp[2]), maxdp[3]) + b;
        tmp3 = max(maxdp[2], maxdp[3]) + c;
        maxdp[1] = tmp1; maxdp[2] = tmp2; maxdp[3] = tmp3;
        
        tmp1 = min(mindp[1], mindp[2]) + a;
        tmp2 = min(min(mindp[1], mindp[2]), mindp[3]) + b;
        tmp3 = min(mindp[2], mindp[3]) + c;
        mindp[1] = tmp1; mindp[2] = tmp2; mindp[3] = tmp3;
    }
    
    int Max = 0;
    int Min = 987654321;
    
    for(i = 1; i <= 3; i++){
        Max = max(Max, maxdp[i]);
        Min = min(Min, mindp[i]);
    } printf("%d %d", Max, Min);
}