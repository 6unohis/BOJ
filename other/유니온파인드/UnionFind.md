- 유니온 파인드의 기본 구성 배열의 모든 부모값들은 해당 노드의 값과 동일하게 시작함

- 이후 간선들을 통해 parent배열의 값들을 모두 갱신함

- 그 첫번째는 해당 노드의 부모를 구하는 것
```c
int find(int i){
    if(parent[i] == i) return i;
    return find(parent[i]);
}
```

- 그 두번째는 간선으로 이어진 두 노드를 합치는 것
```c
void union(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb) parent[a] = b;
}
```

- 부모를 구하는 과정(find)에서 최악의 경우 O(n)의 시간이 걸릴 수 있음 -> 시간이 오래 걸리기 때문에 최적화 과정이 필요함
```c
int find(int i){
    if(parent[i] == i) return i;
    parent[i] = find(parent[i]);
    return parent[i];
}
```