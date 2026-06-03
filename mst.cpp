#include <bits/stdc++.h>
using namespace std;
class DSU
{
private:
    vector<int> par;

public:
    DSU(int n)
    {
        par.resize(n+1);
        for (int i=1;i<=n;;i++)
        {
            par[i]=i;
        }
    }
    void union(int a, int b, par[])
    {
        if (par[a] != par[b])
            par[b] = par[a];
    }
   int find(int x, int par[]) {
    if (par[x] != x)
        par[x] = find(par[x], par); // Path compression
    return par[x];
}

};
//difference with dijkstra 