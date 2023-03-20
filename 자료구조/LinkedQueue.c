//1966
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int selected;
    int prime;
    struct node* Next;
}Node;

typedef struct queue{
    Node* Front;
    Node* Rear;
    int capacity;
}Queue;

void CreateQueue(Queue** Q);
Node* CreateNode(int Prime, int selected);
void Enqueue(Queue** Q, Node* NewNode);
Node* Dequeue(Queue** Q);
int Check(Queue* Q);
int max(int a, int b);

void CreateQueue(Queue** Q){
    (*Q) = (Queue*)malloc(sizeof(Queue));
    (*Q)->Front = NULL;
    (*Q)->Rear = NULL;
    (*Q)->capacity = 0;
}

Node* CreateNode(int Prime, int selected){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->selected = selected;
    NewNode->prime = Prime;
    NewNode->Next = NULL;
    
    return NewNode;
}

void Enqueue(Queue** Q, Node* NewNode){
    Node* front = (*Q)->Front;
    if(front == NULL){
        (*Q)->Front = NewNode;
        (*Q)->Rear = NewNode;
    }else{
        (*Q)->Rear->Next = NewNode;
        (*Q)->Rear = NewNode;
    }
    
    (*Q)->capacity++;
}

Node* Dequeue(Queue** Q){
    Node* CurrentFront = (*Q)->Front;
    
    if((*Q)->Front == (*Q)->Rear){
        (*Q)->Front = NULL;
        (*Q)->Rear  = NULL;
    }else{
        (*Q)->Front = (*Q)->Front->Next;
        CurrentFront->Next = NULL;
    }
    (*Q)->capacity--;
    return CurrentFront;
}

int max(int a, int b){
    if( a <= b) return b;
    else return a;
}

int Check(Queue* Q){
    int top = 0;
    int capacity = Q->capacity;
    Node* Current = Q->Front;
    while(capacity--){
        top = max(Current->prime, top);
        Current = Current->Next;
    }
    
    return top;
}

int main(){
    int T, i, j;
    scanf("%d", &T);
    
    Queue* QList[T];
    for(i = 0; i < T; i++){
        CreateQueue(&QList[i]);
    }
    
    for(i = 0; i < T; i++){
        int N, M;
        scanf("%d %d", &N, &M);
        
        for(j = 0; j < N; j++){
            int Prime;
            scanf("%d", &Prime);
            
            if(j == M){
                Enqueue(&QList[i], CreateNode(Prime, 1));
            }
            else Enqueue(&QList[i], CreateNode(Prime, 0));
        }
        int cnt = 0;
        while(1){
            int Top = Check(QList[i]);
            Node* Current = QList[i]->Front;
            
            if(Current->prime == Top){
                cnt++;
                if(Current->selected == 1) break;
                else Dequeue(&QList[i]);
            } else Enqueue(&QList[i], Dequeue(&QList[i]));
        }
        
        printf("%d\n", cnt);
    }
}

