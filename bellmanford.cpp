#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanford(int v, vector<vector<int>> &edges, int src)
{
    // initally the distance from source to all other vertices is not known and thus infinity
    vector<int> dist(v, 1e8);
    dist[src] = 0;
    // realaxation of all the edges v times ,not (v-1) as we need one additional realxation
    // to detect negative cycle
    for (int i = 0; i < v; i++)
    {
        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                // here is the catch
                if (i == v - 1)
                    return {-1};
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
