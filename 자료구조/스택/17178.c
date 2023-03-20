#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char c;
    int n;
}Node;

int n;
Node stack[555];
int front = 0;
int top = 0;

int compare(const void* a, const void* b){
    Node n1 = *(Node*)a;
    Node n2 = *(Node*)b;
    
    if(n1.c < n2.c) return -1;
    else if(n1.c > n2.c) return 1;
    else{
        if(n1.n < n2.n) return -1;
        else if(n1.n > n2.n) return 1;
        else return 0;
    }
}

int main(){
    int i, j, k;
    scanf("%d", &n);
    
    n *= 5;
    Node Nodes[n];
    Node asc[n];
    
    for(i = 0; i < n; i++){
        char p[10];
        scanf("%s", p);
        
        int len = strlen(p);
        Nodes[i].c = p[0];
        Nodes[i].n = 0;
        
        for(j = 2; j < len; j++) Nodes[i].n = Nodes[i].n * 10 + (p[j] - '0');
    }
    
    memcpy(asc, Nodes, sizeof(Nodes));
    
    qsort(asc, n, sizeof(Node), compare);
    
    for(i = 0; i < n; i++){
        if(asc[front].n == Nodes[i].n && asc[front].c == Nodes[i].c){
            front++;
            
        }
        else{
            if(asc[front].n == stack[top - 1].n && asc[front].c == stack[top - 1].c){
                front++;
                top--;
                i--;
            }else{
                stack[top].n = Nodes[i].n;
                stack[top].c = Nodes[i].c;
                top++;
            }
        } 
    }
    
    for(i = top - 1; i >= 0; i--){
        if(stack[i].n == asc[front].n && stack[i].c == asc[front].c){
            top--;
            front++;
        }
    }
    
    if(top) printf("BAD");
    else printf("GOOD");
}