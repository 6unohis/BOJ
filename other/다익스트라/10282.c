#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2100000000

int t, n, d, c, rear = 0;

typedef struct node{
    int idx;
    int weight;
    struct node* nextnode;
}Node;

Node* Nodes[10001];
int heap[1111111];
int dist[10001];
int _max(int a, int b){if(a <= b) return b; else return a;};
void AddEdge(int start, int target, int Weight){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->idx = target;
    NewNode->weight = Weight;
    NewNode->nextnode = Nodes[start];
    Nodes[start] = NewNode;
}

void swap(int idx1, int idx2){
    int tmp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = tmp;
}

void insert(int now){
    int current = rear;
    heap[rear++] = now;
    
    int parent = current / 2;
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
    rear = 0;
    
    insert(start);
    while(rear){
        int popped = heap[0];
        pop();
 
        Node* Current = Nodes[popped];
        while(Current != NULL){
            int tmp_idx = Current->idx;
            int tmp_weight = Current->weight;
                
            if(dist[tmp_idx] > tmp_weight + dist[popped]){
                dist[tmp_idx] = tmp_weight + dist[popped];
                insert(tmp_idx);
            }
            Current = Current->nextnode;
        }
    }
}

int main(){
    int i, j;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d", &n, &d, &c);
        memset(heap, 0, sizeof(heap));
        for(i = 1; i <= n; i++){
            Nodes[i] = NULL;
            dist[i] = MAX;
        }
        
        while(d--){
            int s, t, w;
            scanf("%d %d %d", &s, &t, &w);
  
            AddEdge(t, s, w);
        }
        
        dij(c);
        int max = -1, ans = 0;
        
        for(i = 1; i <= n; i++){
            if(dist[i] > max && dist[i] != MAX) max = dist[i];
        }
        
        for(i = 1; i <= n; i++){
            if(dist[i] != MAX){
                ans++;
                max = _max(max, dist[i]);
            }
        } printf("%d %d\n", ans, max);
    }
}