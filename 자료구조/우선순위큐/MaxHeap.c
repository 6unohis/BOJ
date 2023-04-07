// 문제 -> 11279
#include<stdio.h>

int rear = 1;
int heap[100002];
int n;

int get_parent(int num){return num / 2;};

void swap(int idx1, int idx2){
    int tmp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = tmp;
}

void insert(int data){
    if(rear == 1) heap[rear++] = data;
    else{
        int current = rear++;
        int parent = get(current);
        heap[current] = data;

        while(current > 0 && parent > 0 && heap[current] > heap[parent]){
            swap(current, parent);
            current = parent;
            parent = get_parent(current);
        }
    }
}

void delete(){
    if(rear == 1) return;
    else if(rear == 2){
        heap[--rear] = 0;
        return;
    }

    int current = 1;
    swap(current, --rear);
    heap[rear] = 0;

    int left = current * 2;
    int right = left + 1;

    while(current <= rear && right <= rear){
        if(heap[left] <= heap[current] && heap[right] <= heap[current]) break;
        else{
            if(heap[left] >= heap[right]){
                swap(left, current);
                current = left;
            }else if(heap[left] <= heap[right]){
                swap(right, current);
                current = right;
            }
        }

        left = current * 2;
        right = left + 1;
    }
}

int main(){
    int i, j;
    scanf("%d", &n);

    for(i = 1; i < 100000; i++) heap[i] = 0;

    while(n--){
        int order;
        scanf("%d", &order);

        if(order == 0){
            printf("%d\n", heap[1]);
            delete();
        }
        else insert(order);
    }
}