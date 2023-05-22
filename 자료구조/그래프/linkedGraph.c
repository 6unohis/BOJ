#include<stdio.h>

typedef struct node{
    int idx;
    struct node* NextNode;
}Node;

Node* Nodes[];

void AddEdge(int start, int target){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->idx = target;
    NewNode->NextNode = Nodes[start];
    Nodes[start] = NewNode;
}