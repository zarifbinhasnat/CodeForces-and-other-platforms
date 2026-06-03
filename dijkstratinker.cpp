#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Adjacency list: adj[u] = { {v1, weight1}, {v2, weight2}, ... }
    vector<vector<pli>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b); // (weight, destination)
    }

    // Distance array
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    // Min-heap priority queue: (distance, node)
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue; // Already processed with a better distance

        for (auto [w, v] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
