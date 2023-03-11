#include<stdio.h>

int main(){
    long long n, m = 1;
    scanf("%lld", &n);
    
    while(m < n) m = m * 2 + 1;
    if(m == n) printf("1\n%lld", n);
    else printf("2\n%lld\n%lld", m ^ n, n);
}