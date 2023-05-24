#include<stdio.h>

int dist[22];
char g[21][21];
int w1[21][21];
int w2[21][21];
int n, res = 987654321;

typedef struct node{
    int Idx;
    int W1;
    int W2;
    int Mul;
}Node;

Node heap[111111];
int rear = 0;

void swap(int idx1, int idx2){
    Node tmp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = tmp;
}

void insert(Node now){
    int current = rear;
    heap[rear++] = now;
    
    int parent = current / 2;
    while(current > 0 && heap[current].Mul < heap[parent].Mul){
        swap(current, parent);
        
        current = parent;
        parent = current / 2;
    }
}

void pop(){
    if(!rear) return;
    int current = 0;
    swap(current, --rear);
    
    int left = current * 2;
    int right = left + 1;
    
    while(1){
        int next;
        if(left >= rear) break;
        if(right >= rear) next = left;
        else{
            if(heap[left].Mul >= heap[right].Mul) next = right;
            else next = left;
        }
        
        if(heap[current].Mul > heap[next].Mul){
            swap(current, next);
            current = next;
        }else break;
        
        left = current * 2;
        right = left + 1;
    }
}

void solve(int idx, int _w1, int _w2){
    int i, j;
    Node start;
    start.Idx = idx, start.W1 = _w1, start.W2 = _w2, start.Mul = _w1 * _w2;
    
    insert(start);
    while(rear){
        Node popped = heap[0];
        int tmp = popped.Idx;
        int tmp_w1 = popped.W1;
        int tmp_w2 = popped.W2;
        pop();
        
        for(j = 0; j < n; j++){
            if(w1[tmp][j] && w2[tmp][j]){
                if(dist[j] <= (tmp_w1 + w1[tmp][j]) * (tmp_w2 + w2[tmp][j])) continue;
                
                Node NewNode;
                NewNode.Idx = j, NewNode.W1 = tmp_w1 + w1[tmp][j], 
                NewNode.W2 = tmp_w2 + w2[tmp][j], NewNode.Mul = NewNode.W1 * NewNode.W2;
                
                dist[j] = NewNode.Mul;
                
                insert(NewNode);
            }
        }
    }
}

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) scanf("%s", g[i]);
    for(i = 0; i < n; i++){
        dist[i] = res;
        for(j = 0; j < n; j++){
            if(g[i][j] >= '1' && g[i][j] <= '9') w1[i][j] = g[i][j] - '0';
        }
    }
    
    for(i = 0; i < n; i++) scanf("%s", g[i]);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(g[i][j] >= '1' && g[i][j] <= '9') w2[i][j] = g[i][j] - '0';
        }
    }
 
    dist[0] = 0;
    solve(0, 0, 0);
    
    if(dist[1] == 987654321) printf("-1");
    else printf("%d", dist[1]);
}
