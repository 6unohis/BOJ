#include<stdio.h>

int n, m;
int parent[100001];
int arr[100001];

int find(int i){
    if(parent[i] == i) return i;
    parent[i] = find(parent[i]);
    return parent[i];
}

void uni(int s, int e){
    int ps = find(s);
    int pe = find(e);
    if(ps != pe) parent[ps] = pe;
}

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    
    for(i = 1; i <= n; i++) parent[i] = i;
    
    while(m--){
        int s, e;
        scanf("%d %d", &s, &e);
        
        uni(s, e);
    }
    
    for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for(i = 1; i <= n; i++){
        parent[i] = find(i);
    }
    
    int tmp = parent[arr[1]];
    int cnt = 0;
    for(i = 2; i <= n; i++){
        if(parent[arr[i]] != tmp){
            tmp = parent[arr[i]];
            cnt++;
        }
    } printf("%d", cnt);
}