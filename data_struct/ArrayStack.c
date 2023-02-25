//10828
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10000

typedef int ElementType;

typedef struct stack{
    int* stack;
    int Top;
}ArrayStack;

void CreateStack(ArrayStack** Stack);
void Push(ArrayStack* Stack, int num);
int  Pop(ArrayStack* Stack);
int  Size(ArrayStack* Stack);
int  Empty(ArrayStack* Stack);
int  Top(ArrayStack* Stack);

void CreateStack(ArrayStack** Stack){
    (*Stack)        = (ArrayStack*)malloc(sizeof(Stack));
    (*Stack)->stack = (int*)malloc(sizeof(int) * SIZE);
    (*Stack)->Top   = 0;
}

void Push(ArrayStack* Stack, ElementType num){
    int Position = (Stack)->Top;
    
    Stack->stack[Position] = num;
    Stack->Top++;
}

ElementType Pop(ArrayStack* Stack){
    if(Empty(Stack)) return -1;
    else{
        int Position = --(Stack->Top);
        return Stack->stack[Position];
    }
}

int Size(ArrayStack* Stack){
    if(Empty(Stack)) return 0;
    else return Stack->Top;
}

int Empty(ArrayStack* Stack){
    if(!Stack->Top) return 1;
    else return 0;
}

int Top(ArrayStack* Stack){
    int Position = Stack->Top - 1;
    if(Empty(Stack)) return -1;
    else return Stack->stack[Position];
}

int main(){
    int N,num = 0;
    char order[6];
    
    scanf("%d", &N);
    getchar();
    
    ArrayStack* Stack;
    CreateStack(&Stack);
    
    for(int i = 0; i < N; i++){
        scanf("%s", order);
        getchar();
        
        if(!strcmp(order,"push")){
            scanf("%d", &num);
            getchar();
            Push(Stack, num);
        }
        else if(!strcmp(order,"pop"))   printf("%d\n",Pop(Stack));
        else if(!strcmp(order,"size"))  printf("%d\n",Size(Stack));
        else if(!strcmp(order,"empty")) printf("%d\n",Empty(Stack));
        else if(!strcmp(order,"top"))   printf("%d\n",Top(Stack));
    }
    
    free(Stack->stack);
    free(Stack);
    
}