#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank, blackCount;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        blackCount.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                blackCount[rootX] += blackCount[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                blackCount[rootY] += blackCount[rootX];
            } else {
                parent[rootY] = rootX;
                blackCount[rootX] += blackCount[rootY];
                rank[rootX]++;
            }
        }
    }

    void addBlack(int x) {
        blackCount[find(x)]++;
    }

    int getBlackCount(int x) {
        return blackCount[find(x)];
    }
};

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n + 1);
        string s;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        cin >> s;

        DSU dsu(n);

        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '0') {
                dsu.addBlack(i); // Mark black nodes
            }
        }

        for (int i = 1; i <= n; ++i) {
            dsu.unite(i, p[i]); // Create the graph connections
        }

        for (int i = 1; i <= n; ++i) {
            cout << dsu.getBlackCount(i) << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
