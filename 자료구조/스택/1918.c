#include<stdio.h>
#include<string.h>

char arr[110];
char stack[110];
char ans[110];
int check[50];
int rear = 0;
int top = 0;

int main(){
    int i, j;
    scanf("%s", arr);
    
    check[42] = 2; check[43] = 1; check[47] = 2; check[45] = 1;
    
    int len = strlen(arr);
    for(i = 0; i < len; i++){
        if(arr[i] <= 'Z' && arr[i] >= 'A') ans[rear++] = arr[i];
        else if(arr[i] == '(') stack[++top] = arr[i];
        else if(arr[i] == ')'){
            while(top >= 1){
                if(stack[top] == '('){
                    top--;
                    break;
                }
                else ans[rear++] = stack[top--];
            }
        }else{
            char tmp = arr[i];
            if(check[tmp] > check[stack[top]]) stack[++top] = tmp;
            else if(check[tmp] < check[stack[top]]){
                while(top && check[stack[top]]) ans[rear++] = stack[top--];
                stack[++top] = tmp;
            }else{
                ans[rear++] = stack[top--];
                stack[++top] = tmp;
            }
        }
    }
    
    for(i = top; i >= 1; i--) ans[rear++] = stack[i];
    
    for(i = 0; i < rear; i++) printf("%c", ans[i]);
}

