#include<stdio.h>
#include<string.h>

int n, x;
int heap[111111];
int count[111111];
int arr[111111];
int rear = 0;

int max(int a, int b){if(a <= b) return b; else return a;}

void swap(int idx1, int idx2){
    int tmp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = tmp;
}

void insert(int idx){
    int current = rear;
    heap[rear++] = idx;
    
    int parent = current/ 2;
    while(current > 0 && count[heap[current]] < count[heap[parent]]){
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
            if(count[heap[left]] >= count[heap[right]]) next = right;
            else next = left;
        }
        
        if(count[heap[current]] > count[heap[next]]){
            swap(current, next);
            current = next;
        }else break;
        
        left = current * 2;
        right = left + 1;
    }
}

int solve(int cnt){
    int i, j, res = -1;
    rear = 0;
    
    for(i = 0; i <= cnt; i++) heap[i] = count[i] = 0;
    for(i = 1; i <= cnt; i++) insert(i);
    
    for(i = 1; i <= n; i++){
        int t = arr[i];
        int now_idx = heap[0];
        pop();
        
        count[now_idx] += t;
        res = max(res, count[now_idx]);
        insert(now_idx);
    }
    
    if(res > x) return 0;
    else return 1;
}

int main(){
    int i, j;
    scanf("%d %d", &n, &x);
    
    for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
    
    int mid;
    int left = 1;
    int right = n;
    while(left < right){
        mid = (left + right) / 2;
        int tmp = solve(mid);
        
        if(!tmp) left = mid + 1;
        else right = mid;
        
    } printf("%d", (left + right) / 2);
}