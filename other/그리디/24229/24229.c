#include<stdio.h>
#include<stdlib.h>

int n;

typedef struct node{
    int s;
    int e;
}Node;

int compare(const void* a, const void* b){
    Node n1 = *(Node*)a;
    Node n2 = *(Node*)b;
    
    if(n1.s < n2.s) return -1;
    else if(n1.s > n2.s) return 1;
    else return 0;
}

int max(int a, int b){if(a <= b) return b; else return a;};

int main(){
    int i, j;
    scanf("%d", &n);
    
    Node Nodes[n];
    for(i = 0; i < n; i++) scanf("%d %d", &Nodes[i].s, &Nodes[i].e);
    
    qsort(Nodes, n, sizeof(Node), compare);
    
    for(i = 0; i < n - 1; i++){
        if(Nodes[i].e >= Nodes[i + 1].s){
            if(Nodes[i].e > Nodes[i + 1].e) Nodes[i + 1].e = Nodes[i].e;
            
            Nodes[i + 1].s = Nodes[i].s;
        }
    }
    
    int tmp = 0;
    int idx;
    for(i = 0; i < n; i++){
        if(tmp >= Nodes[i].s){
            idx = i;
            tmp = max(tmp, Nodes[i].e + Nodes[i].e - Nodes[i].s);
        }
    }
    
    printf("%d", Nodes[idx].e);
    
}