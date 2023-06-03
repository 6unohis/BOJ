#include<stdio.h>

int min_tree[444444];
int max_tree[444444];
int arr[111111];
int n, m;

int min(int a, int b){if(a <= b) return a; else return b;}
int max(int a, int b){if(a <= b) return b; else return a;}

void init(int idx, int s, int e){
    if(s == e){
        min_tree[idx] = arr[s];
        max_tree[idx] = arr[s];
        return;
    }
    
    int mid = (s + e) / 2;
    init(idx * 2, s, mid);
    init(idx * 2 + 1, mid + 1, e);
    
    min_tree[idx] = min(min_tree[idx * 2], min_tree[idx * 2 + 1]);
    max_tree[idx] = max(max_tree[idx * 2], max_tree[idx * 2 + 1]);
}

int query_max(int idx, int s, int e, int l, int r){
    if(s > r || e < l) return 0;
    if(l <= s && e <= r) return max_tree[idx];
    
    int mid = (s + e) / 2;
    return max(query_max(idx * 2, s, mid, l, r), query_max(idx * 2 + 1, mid + 1, e, l, r));
}

int query_min(int idx, int s, int e, int l, int r){
    if(s > r || e < l) return 1111111111;
    if(l <= s && e <= r) return min_tree[idx];
    
    int mid = (s + e) / 2;
    return min(query_min(idx * 2, s, mid, l, r), query_min(idx * 2 + 1, mid + 1, e, l, r));
}

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    
    for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
    init(1, 1, n);
    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d %d\n", query_min(1, 1, n, a, b), query_max(1, 1, n, a, b));
    }
}