#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n + 1, vector<int>(n + 1)); // 1-based indexing
    vector<int> suff(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            if (a[i][j] != 1) break;
            suff[i]++;
        }
    }

    multiset<int> s(suff.begin() + 1, suff.end());

    int ans = 1;
    while (!s.empty()) {
        int cur = *s.begin();
        if (cur >= ans) {
            ans++;
        }
        s.erase(s.begin()); // Fix: Use erase instead of extract
    }

    cout << min(ans, n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
