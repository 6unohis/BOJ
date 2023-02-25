//10845
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 2000001

typedef struct Queue{
    int* buf;
    int  Front;
    int  Rear;
}ArrayQueue;

void CreateQueue(ArrayQueue** Queue);
void Push(ArrayQueue* Queue, int Num);// EnQueue
int  Pop(ArrayQueue* Queue);
int  Size(ArrayQueue* Queue);
int  Empty(ArrayQueue* Queue);
int  Front(ArrayQueue* Queue);
int  Back(ArrayQueue* Queue);

void CreateQueue(ArrayQueue** Queue){
    (*Queue) = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    (*Queue)->buf = (int*)malloc(sizeof(int) * SIZE);
    (*Queue)->Front = 0;
    (*Queue)->Rear  = 0;
}

void Push(ArrayQueue* Queue, int Num){
    int Position = Queue->Rear;
    Queue->buf[Position] = Num;
    Queue->Rear++;
}

int Pop(ArrayQueue* Queue){
    
    if(Empty(Queue)) return -1;
    else return Queue->buf[(Queue->Front)++];
}

int Size(ArrayQueue* Queue){
    return (Queue->Rear) - (Queue->Front);
}

int Empty(ArrayQueue* Queue){
    if(Queue->Front == Queue->Rear) return 1;
    else return 0;
}

int Front(ArrayQueue* Queue){
    int Position = Queue->Front;
    if(Empty(Queue)) return -1;
    else return Queue->buf[Position];
}

int Back(ArrayQueue* Queue){
    int Position = Queue->Rear;
    if(Empty(Queue)) return -1;
    else return Queue->buf[Position - 1];
}

int main(){
    int  Num, N = 0;;
    
    ArrayQueue* Queue;
    CreateQueue(&Queue);
    
    scanf("%d", &N);
    getchar();
    
    for(int i = 0; i < N; i++){
        char order[6];
        scanf("%s", order);
        getchar();
        
        if(!strcmp(order,"push")){
            scanf("%d", &Num);
            getchar();
            Push(Queue, Num);
        }
        else if(!strcmp(order,"pop"))   printf("%d\n",Pop(Queue));
        else if(!strcmp(order,"size"))  printf("%d\n",Size(Queue));
        else if(!strcmp(order,"empty")) printf("%d\n",Empty(Queue));
        else if(!strcmp(order,"front")) printf("%d\n",Front(Queue));
        else if(!strcmp(order,"back"))  printf("%d\n",Back(Queue));
    }
    
    free(Queue->buf);
    free(Queue);
    
}