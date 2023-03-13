#include<stdio.h>
#include<string.h>

char arr[510000];

int main(){
    int i, j;
    int res = -1;
    scanf("%s", arr);
    
    int len = strlen(arr);
    char tmp = arr[0];
    for(i = 1; i < len; i++){
        if(arr[i] != tmp){
            res = 1;
            break;
        }
    }
    
    if(res > 0){
        int left = 0;
        int right = len - 1;
        
        while(left <= right){
            if(arr[left] != arr[right]){
                printf("%d", len);
                return 0;
            }
            
            left++;
            right--;
        }
        
        printf("%d", len - 1);
        return 0;
    }else{
        printf("-1");
        return 0;
    }
}