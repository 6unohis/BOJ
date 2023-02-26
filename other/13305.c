#include<stdio.h>

typedef struct node{
    int fuel;
    int next;
}Node;

int n;
Node Nodes[100001];
long long answer = 0;

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 1; i < n; i++) scanf("%d", &Nodes[i].next);
    for(i = 1; i <= n; i++) scanf("%d", &Nodes[i].fuel);
    
    long long min = Nodes[1].fuel;
    for(i = 1; i < n; i++){
        if(min > Nodes[i].fuel) min = Nodes[i].fuel;
        
        answer += Nodes[i].next * min;
    }
    
    printf("%lld", answer);
}
