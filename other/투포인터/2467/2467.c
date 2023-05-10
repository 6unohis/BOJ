#include<stdio.h>
#include<stdlib.h>

int arr[100001];
int n;

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
    int left = 1;
    int right = n;
    int left_num = arr[1], right_num = arr[right];
    int min = abs(arr[left] + arr[right]);
    while(left < right){
        int tmp1 = arr[left] + arr[right];
        
        if(abs(tmp1) < min){
            min = abs(tmp1);
            left_num = arr[left];
            right_num = arr[right];
        }
        
        if(tmp1 > 0) right--;
        else if(tmp1 < 0) left++;
        else break;
    } printf("%d %d", left_num, right_num);
}