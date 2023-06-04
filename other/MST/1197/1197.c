#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int s;
    int e;
    int w;
}Node;

int V, E;
int parent[11111];

int compare(const void* a, const void* b){
    Node n1 = *(Node*)a;
    Node n2 = *(Node*)b;
    
    if(n1.w < n2.w) return -1;
    else if(n1.w > n2.w) return 1;
    else return 0;
}

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    
    parent[a] = b;
}

int main(){
    int i, j;
    scanf("%d %d", &V, &E);
    
    Node Nodes[E];

    for(i = 0; i < E; i++) scanf("%d %d %d", &Nodes[i].s, &Nodes[i].e, &Nodes[i].w);
    for(i = 1; i <= V; i++) parent[i] = i;
    
    qsort(Nodes, E, sizeof(Node), compare);
    
    int ans = 0;
    for(i = 0; i < E; i++){
        if(find(Nodes[i].s) != find(Nodes[i].e)){
            Union(Nodes[i].s, Nodes[i].e);
            ans += Nodes[i].w;
        }
    } printf("%d", ans);
}
