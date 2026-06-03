#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pli>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    vector<vector<int >>path;
    dist[1] = 0;
//initialise the first column with 1 
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(make_pair(0, 1));

    while (!pq.empty())
    {
        pli top = pq.top();
        pq.pop();
        ll curerntcost = top.first;
        int u = top.second;

        if (curerntcost > dist[u])
            continue;

        for (int i = 0; i < adj[u].size(); ++i)
        {
            ll w = adj[u][i].first;
            int v = adj[u][i].second;

            if (dist[v] > curerntcost+ w)
            {
                dist[v] = curerntcost + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == LLONG_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
