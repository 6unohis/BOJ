#include<stdio.h>

int n, m, k;
int min(int a, int b){if(a <= b) return a; else return b;};
int main(){
    int i, j;
    scanf("%d %d %d", &n, &m, &k);
    
    int last = 987654321;
    int sum = 0;
    for(i = 1; i <= m; i++){
        int t, r;
        scanf("%d %d", &t, &r);
        
        last = min(last, t);
        sum += r;
        
        if(sum > k){
            printf("%d %d", i, last);
            return 0;
        }
    } printf("-1");
}