// 문제 -> 1927
#include<stdio.h>

int n;
int rear = 1;
int heap[100001];

int get_parent(int num){return num/2;};

void swap(int idx1, int idx2){
    int tmp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = tmp;
}

void insert(int data){
    int current = rear;
    heap[rear++] = data;

    int parent = get_parent(current);

    while(current > 1 && heap[current] < heap[parent]){
        swap(current, parent);

        current = parent;
        parent = get_parent(current);
    }
}

void delete(){
    if(rear == 1) return ;
    
    int current = 1;
    swap(current, --rear);
    heap[rear] = 0;

    int left = current * 2;
    int right = current * 2 + 1;

    while(1){
        int next;
        if(left >= rear) break;
        if(rear >= rear) next = left;
        else{
            if(heap[left] >= heap[right]) next = right;
            else next = left;
        }

        if(heap[current] > heap[next]){
            swap(current, next);
            current = next;
        }else break;

        left = current * 2;
        right = current * 2 + 1;
    }
}

int main(){
    int i, j;
    scanf("%d", &n);

    while(n--){
        int order;
        scanf("%d", &order);

        if(order == 0){
            printf("%d\n", heap[1]);
            delete();
        }else insert(order);
    }
}