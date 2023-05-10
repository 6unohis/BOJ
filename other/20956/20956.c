#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int a;
    int idx;
}Node;

int compare_asc(const void* a, const void* b){
    Node n1 = *(Node*)a;
    Node n2 = *(Node*)b;
    if(n1.a > n2.a) return -1;
    else if(n1.a < n2.a) return 1;
    else{
        if(n1.idx < n2.idx) return -1;
        else if(n1.idx > n2.idx) return 1;
        else return 0;
    }
}

int compare_desc(const void* a, const void* b){
    Node n1 = *(Node*)a;
    Node n2 = *(Node*)b;
    if(n1.a > n2.a) return -1;
    else if(n1.a < n2.a) return 1;
    else{
        if(n1.idx > n2.idx) return -1;
        else if(n1.idx < n2.idx) return 1;
        else return 0;
    }
}
int n, m, rear1 = 0, rear2 = 0, state = 0, cnt = 0;
int v[100001];
int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    
    Node Nodes_asc[n];
    Node Nodes_desc[n];
    
    for(i = 0; i < n; i++){
        scanf("%d", &Nodes_asc[i].a);
        Nodes_asc[i].idx = i;
        
        Nodes_desc[i].a = Nodes_asc[i].a;
        Nodes_desc[i].idx = Nodes_asc[i].idx;
    }
    
    qsort(Nodes_asc, n, sizeof(Node), compare_asc);
    qsort(Nodes_desc, n, sizeof(Node), compare_desc);
    
    while(rear1 < n && rear2 < n && cnt < m){
        if(!state){
            Node tmp = Nodes_asc[rear1];
            if(!v[tmp.idx]){
                v[tmp.idx] = 1;
                if(tmp.a % 7 == 0) state = 1;
                printf("%d\n", tmp.idx + 1);
                cnt++;
            }
            
            rear1++;
        }else{
            Node tmp =  Nodes_desc[rear2];
            if(!v[tmp.idx]){
                v[tmp.idx] = 1;
                if(tmp.a % 7 == 0) state = 0;
                printf("%d\n", tmp.idx + 1);
                cnt++;
            }
            
            rear2++;
        }
    }
}