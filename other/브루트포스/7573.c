#include<stdio.h>

typedef struct node{
    int y;
    int x;
}Node;

Node Nodes[33333];
int rear = 1, res = 1;
int n, l, m;

int max(int a, int b){if(a <= b) return b; else return a;};

void fishing(int y, int x){
    int i, j, ny, nx, ny_tmp, nx_tmp;
    int nl = l / 2;
    int sx = 1;
    int sy = nl - 1;
    
    while(sx <= sy){
        int res1 = 0;
        int res2 = 0;
        ny = y + sy;
        nx = x + sx;
        ny_tmp = y + sx;
        nx_tmp = x + sy;
        
        sx++;
        sy--;
        
        if(ny > n || nx > n || nx <= 0 || ny <= 0
        || ny_tmp > n || nx_tmp > n || ny_tmp <= 0 || nx_tmp <= 0) continue;
        
        for(i = 1; i <= m; i++){
            if(Nodes[i].y >= y && Nodes[i].y <= ny && Nodes[i].x >= x && Nodes[i].x <= nx) res1++;
            if(Nodes[i].y >= y && Nodes[i].y <= ny_tmp && Nodes[i].x >= x && Nodes[i].x <= nx_tmp) res2++;
        }
        
        res = max(res, max(res1, res2));
    }
}

int main(){
    int i, j;
    scanf("%d %d %d", &n, &l, &m);
    
    for(i = 1; i <= m; i++){
        scanf("%d %d", &Nodes[i].y, &Nodes[i].x);
    } rear = m + 1;
    
    for(i = 1; i <= m; i++){
        for(j = i + 1; j <= m; j++){
            Nodes[rear].y = Nodes[i].y;
            Nodes[rear].x = Nodes[j].x;
            rear++;
            Nodes[rear].y = Nodes[j].y;
            Nodes[rear].x = Nodes[i].x;
            rear++;
        }
    }
    
    for(i = 1; i < rear; i++) fishing(Nodes[i].y, Nodes[i].x);

    printf("%d\n", res);
}