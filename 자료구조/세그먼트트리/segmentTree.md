- 세그트리 초기화
```c
void init(int idx, int s, int e){
    if(s == e){
        tree[idx] = arr[s];
        return;
    }

    int mid = (s + e) / 2;
    init(idx * 2, s, mid);
    init(idx * 2 + 1, mid + 1, e);

    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
```

- 세그트리 구간합 쿼리
```c
int query(int idx, int s, int e, int l, int r){
    if(s > r || e < l) return 0;
    if(l <= s && r <= e) return tree[idx];
    int mid = (s + e) / 2;
    return query(idx * 2, s, mid, l, r) + query(idx* 2 + 1, mid + 1, e, l, r);
}
```

- 세그트리 업데이트 쿼리
```c
void update(int now, int s, int e, int idx, int val){
    if(e < idx || idx < s) return;
    if(s == e){
        tree[now] = val;
        return;
    }

    int mid = (s + e) / 2;
    update(now * 2, s, mid, idx, val);
    update(now * 2 + 1, mid + 1, idx, val);
    tree[now] = tree[now * 2] + tree[now * 2 + 1];
}
```

**세그트리의 중요점**

- 각 tree[node]를 무엇으로 선언할 것인가