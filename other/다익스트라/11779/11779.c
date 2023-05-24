#include<stdio.h>
#include<string.h>

int n, m, a, b;
int g[1001][1001];
int dist[1001];
int tmp[1001];
int heap[111111];
int rear = 0;

void swap(int idx1, int idx2){
    int tmp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = tmp;
}

void insert(int idx){
    int current = rear;
    heap[rear++] = idx;
    
    int parent = current/ 2;
    while(current > 0 && dist[heap[current]] < dist[heap[parent]]){
        swap(current, parent);
        
        current = parent;
        parent = current / 2;
    }
}

void pop(){
    if(!rear) return;
    int current = 0;
    swap(current, --rear);
    heap[rear] = 0;
    
    int left = current * 2;
    int right = left + 1;
    
    while(1){
        int next;
        if(left >= rear) break;
        if(right >= rear) next = left;
        else{
            if(dist[heap[left]] >= dist[heap[right]]) next = right;
            else next = left;
        }
        
        if(dist[heap[current]] > dist[heap[next]]){
            swap(current, next);
            current = next;
        }else break;
        
        left = current * 2;
        right = left + 1;
    }
}

void dij(int start){
    int i, j;
    dist[start] = 0;
    
    insert(start);
    while(rear){
        int idx = heap[0];
        pop();
        
        for(j = 1; j <= n; j++){
            if(g[idx][j] >= 0 && dist[j] > dist[idx] + g[idx][j]){
                dist[j] = dist[idx] + g[idx][j];
                tmp[j] = idx;
                insert(j);
            }
        }
    }
}

void go(int idx, int depth){
    if(!tmp[idx]){
        printf("%d\n%d ", depth, idx);
        return;
    }else{
        go(tmp[idx], depth + 1);
        printf("%d ", idx);
    }
}

int main(){
    int i, j;
    scanf("%d", &n);
    scanf("%d", &m);
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++) g[i][j] = -1;
    }
    
    for(i = 1; i <= n; i++) dist[i] = 1111111111;
    
    while(m--){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        
        if(g[s][e] == -1 || g[s][e] > w) g[s][e] = w;
    }
    scanf("%d %d", &a, &b);
    
    dij(a);
    printf("%d\n", dist[b]);
    go(b, 1);
}