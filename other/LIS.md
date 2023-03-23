<h1>LIS : 최장 증가 부분 수열</h1>

- 원소가 n개인 배열 내의 부분 수열 중, 각각의 원소가 이전 원소보다 크면서, 수열의 길이가 최대인 수열

<h2>DP</h2>

- 가장 흔하게 접할 수 있는 풀이

```c
// 한 요소를 기준으로 그 요소의 앞부터 확인
for(i = 0; i < n; i++){
    dp[i] = 1;
    for(j = 0; j < i; j++){
        if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
}

// 한 요소를 기준으로 뒤에 있는 요소들과 비교
for(i = 0; i < n; i++){
    for(j = i; j < n; j++){
        if(arr[i] < arr[j]) dp[j] = max(dp[j], dp[i] + 1);
    }
}
```

- 이 풀이의 시간복잡도는 O(n^2)


> 관련 문제
>
> 1965

<h2>이분 탐색</h2>

- 위 풀이의 시간 복잡도는 O(n^2)이기 때문에, 시간 단축을 위해서는 다른 풀이 필요함

- 시간 복잡도를 o(N) ~ O(NlogN) 정도로 개선시켜보자

- 입력받은 배열의 진행 방향을 한 방향으로 유지하되 O(1) 또는 O(logN)의 알고리즘을 추가적으로 사용할 수 있으며 LIS에서는 이분 탐색을 사용함

- LIS에는 값들을 정렬시키며 삽입하고, 최대 길이 변수를 정의하여 상황에 맞게 갱신함

- arr, LIS 두 배열을 사용하고 LIS배열은 오름차순으로 정렬되도록 함

```c
// 이분 탐색 구현
int binary_search(int left, int right, int target){
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(LIS[mid] < target) left = mid + 1;
        else right = mid;
    } return right;
}

// 두 가지 경우를 확인하고, ans는 최대 길이를 나타내는 변수
for(i = 0; i < n; i++){
    // LIS 마지막보다 arr배열 요소가 큰 경우
    if(LIS[ans] < arr[i]) LIS[++ans] = arr[i];
    // 아닌 경우
    else{
        //이분탐색을 활용하여 LIS배열 해당 위치에 arr배열 요소를 삽입함
        int pos = binary_search(0, ans, arr[i]);
        LIS[pos] = arr[i];
    }
}
```
