#include<stdio.h>
#include<string.h>

int n, m, x;
int g[1001][1001];
int g2[1001][1001];
int dist[1001];
int tmp[1001];
int heap[11111];
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
            if(g[idx][j] && dist[j] > dist[idx] + g[idx][j]){
                dist[j] = dist[idx] + g[idx][j];
                insert(j);
            }
        }
    }
}

void dij2(int start){
    int i, j;
    dist[start] = 0;
    
    insert(start);
    while(rear){
        int idx = heap[0];
        pop();
        
        for(j = 1; j <= n; j++){
            if(g2[idx][j] && dist[j] > dist[idx] + g2[idx][j]){
                dist[j] = dist[idx] + g2[idx][j];
                insert(j);
            }
        }
    }
}

int main(){
    int i, j;
    scanf("%d %d %d", &n, &m, &x);
    
    for(i = 1; i <= n; i++) dist[i] = 987654321;
    
    while(m--){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        
        if(!g[s][e] || g[s][e] > w) g[s][e] = w;
        if(!g2[e][s] || g2[e][s] > w) g2[e][s] = w;
    }
    
    dij(x);
    memset(heap, 0, sizeof(heap));
    for(i = 1; i <= n; i++) tmp[i] = dist[i];
    for(i = 1; i <= n; i++) dist[i] = 987654321;
    
    int ans = 0;
    dij2(x);
    for(i = 1; i <= n; i++){
        tmp[i] += dist[i]; 
        if(ans < tmp[i]) ans = tmp[i];
    }
    printf("%d", ans);
}