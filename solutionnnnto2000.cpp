 
int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        Addedge(x, y, z);
    }
    for (int i = 1; i <= n; i++) d[i] = 1e18;
    int ans = 0;
    for (int i = 0; i < k; i++){
        int x; LL y;
        scanf("%d%I64d", &x, &y);
        if (d[x] != 1e18) ans++;
        d[x] = min(d[x], y);
        f[x] = 1;
    }
    for (int i = 2; i <= n; i++) if (f[i]) Q.push(Heap(i, d[i]));
    Q.push(Heap(1, 0));
    d[1] = 0;
    for (int i = 1; i <= n; i++){
        if (Q.empty()) break;
        while (1){
            now = Q.top(); Q.pop();
            if (!v[now.x]) break;
        }
        int x = now.x;
        v[x] = 1;
        for (int p = head[x]; p != -1; p = e[p].next)
        if (d[e[p].y] > d[x] + e[p].d){
            Q.push(Heap(e[p].y, d[x] + e[p].d));
            d[e[p].y] = d[x] + e[p].d;
            f[e[p].y] |= 2;
        }else if (d[e[p].y] == d[x] + e[p].d) f[e[p].y] |= 2;
    }
    for (int i = 2; i <= n; i++) if (f[i] == 3) ans++;
    printf("%d\n", ans);
}