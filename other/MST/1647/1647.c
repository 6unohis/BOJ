#include<stdio.h>
#include<stdlib.h>

int n, m;
int parent[111111];

typedef struct node{
    int start;
    int end;
    int weight;
}Node;

int compare(const void* a, const void* b){
    Node n1 = *(Node*)a;
    Node n2 = *(Node*)b;
    
    if(n1.weight < n2.weight) return -1;
    else if(n1.weight > n2.weight) return 1;
    else return 0;
}

int find(int i){
    if(parent[i] == i) return i;
    parent[i] = find(parent[i]);
    return parent[i];
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    
    parent[a] = b;
}

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    
    Node Nodes[m];
    for(i = 0; i < m; i++) scanf("%d %d %d", &Nodes[i].start, &Nodes[i].end, &Nodes[i].weight);
    qsort(Nodes, m, sizeof(Node), compare);
    
    for(i = 1; i <= n; i++) parent[i] = i;
    int ans = 0, max = -1;
    
    for(i = 0; i < m; i++){
        if(find(Nodes[i].start) != find(Nodes[i].end)){
            Union(Nodes[i].start, Nodes[i].end);
            ans += Nodes[i].weight;
            
            if(max < Nodes[i].weight) max = Nodes[i].weight;
        }
    }
    
    printf("%d", ans-max);
}