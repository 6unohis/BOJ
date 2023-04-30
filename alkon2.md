<h1>DP</h1>

- dp핵심 : 점화식으로 나타내기 / 배열의 인덱스에 따른 값을 정확히 정의하기

<h2>15990</h2>

- dp[100000][3] => dp[i][j]로 나타내며, j로 끝나는 i를 나타내는 경우의 수 // 연속되는 수를 사용하면 안됨

- dp[i][3] 3으로 끝나는 경우의 수.. 즉, dp[i][3] = dp[i - 3][1] + dp[i - 3][2]

```c
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100001
#define div 1000000009

long long dp[100001][4];

int n, i, j;

int main(){
    int t;
    scanf("%d", &t);
    
    for(i = 1; i < SIZE; i++){
        for(j = 1; j <= 3; j++) dp[i][j] = 0;
    }
    
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    
    for(i = 4; i < SIZE; i++){
        for(j = 1; j <= 3; j++){
            if(j == 1) dp[i][j] = (dp[i - j][2] + dp[i - j][3]) % div;
            else if(j == 2) dp[i][j] = (dp[i - j][1] + dp[i - j][3]) % div;
            else if(j == 3) dp[i][j] = (dp[i - j][1] + dp[i - j][2]) % div;
        }
    }
    
    while(t--){
        scanf("%d", &n);
        
        long long sum = 0;
        sum = (dp[n][1] + dp[n][2] + dp[n][3]) % div;
        
        printf("%lld\n", sum);
    }
}
```

<h2>2096</h2>

- 특별한 점화식이 필요한건 아니지만, 주의할 점들이 있음

- 메모리 제한 -> 4MB라서 15990과 같은 크기의 배열 생성시에는 메모리 초과 발생.. -> 최대값과 최소값을 나타내는 크기가 3인 배열 2개만을 생성해야함

- 또한 반복문을 통해 최대값과 최소값을 갱신하지만, 배열에 바로 갱신해선 안되고 다른 변수를 통해 갱신한 후 대입하는 방식을 사용해야함

```c
#include<stdio.h>

int mindp[4];
int maxdp[4];
int n;

int max(int a, int b){if(a <= b) return b; else return a;};
int min(int a, int b){if(a <= b) return a; else return b;};

int main(){
    int i, j;
    scanf("%d", &n);
    
    scanf("%d %d %d", &maxdp[1], &maxdp[2], &maxdp[3]);
    mindp[1] = maxdp[1]; mindp[2] = maxdp[2]; mindp[3] = maxdp[3];
    
    for(i = 2; i <= n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int tmp1, tmp2, tmp3;
        tmp1 = max(maxdp[1], maxdp[2]) + a;
        tmp2 = max(max(maxdp[1], maxdp[2]), maxdp[3]) + b;
        tmp3 = max(maxdp[2], maxdp[3]) + c;
        maxdp[1] = tmp1; maxdp[2] = tmp2; maxdp[3] = tmp3;
        
        tmp1 = min(mindp[1], mindp[2]) + a;
        tmp2 = min(min(mindp[1], mindp[2]), mindp[3]) + b;
        tmp3 = min(mindp[2], mindp[3]) + c;
        mindp[1] = tmp1; mindp[2] = tmp2; mindp[3] = tmp3;
    }
    
    int Max = 0;
    int Min = 987654321;
    
    for(i = 1; i <= 3; i++){
        Max = max(Max, maxdp[i]);
        Min = min(Min, mindp[i]);
    } printf("%d %d", Max, Min);
}
```

<h2>10942</h2>

- dp[i][j] => i부터 j인덱스까지 팰린드롬이 맞는지.. 맞으면 1 아니면 0

- dp[i][j]가 팰린드롬이려면 arr[i] == arr[j] 이면서 dp[i - 1][j - 1] == 1이면 됨.. => 표현은 쉽지만 바로 이렇게 함수 작성 시 값들이 모두 채워지지 않음

- 배열을 직접 표현해보면 좌측 아래의 값에 영향을 받는다는 것을 알 수 있고 그 전에 모든 dp[i][i + 1] 값을 초기화시켜줘야 함

- 이후, i나 j의 일방향이 아닌 대각선 방향으로 반복문을 진행시켜야 함

```c
#include<stdio.h>

int n;
int arr[2001];
int dp[2001][2001];

int main(){
    int i, j;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        dp[i][i] = 1;
    }
    
    for(i = 1; i < n; i++){
        if(arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
    }
    
    for(j = 3; j <= n; j++){
        int k = j;
        i = 1;
        while(k <= n){
            if(arr[k] == arr[i] && dp[i + 1][k - 1]) dp[i][k] = 1;
            k++;
            i++;
        }
    }
    
    int order;
    scanf("%d", &order);
    
    while(order--){
        int s, t;
        scanf("%d %d", &s, &t);
        printf("%d\n", dp[s][t]);
    }
}
```

<hr>

<h1>Graph</h1>

- 해결하려는 문제에 따라 DFS또는 BFS 선택해야함

- 최단거리 -> BFS / 특징별 구분이 필요한 경우 -> DFS

- BFS와 visited배열을 활용해서 특징 구분이 가능하긴 하지만 그래도 DFS를 사용하는 편

