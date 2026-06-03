#include <bits/stdc++.h>
using namespace std;

void tc() {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> ve(n, vector<long long>(m));
    vector<long long> p(n, -1);
    bool valid = true;

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> ve[i][j];
        }
        sort(ve[i].begin(), ve[i].end());
    }

    vector<pair<long long, long long>> cows; // (smallest card, cow index)
    for (long long i = 0; i < n; i++) {
        cows.push_back({ve[i][0], i});
    }
    sort(cows.begin(), cows.end());

    long long lastCard = -1;
    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < n; j++) {
            long long idx = cows[j].second;
            if (ve[idx][i] <= lastCard) {
                cout << "-1\n";
                return;
            }
            lastCard = ve[idx][i];
        }
    }

    for (long long j = 0; j < n; j++) {
        cout << cows[j].second + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long T;
    cin >> T;
    while (T--) {
        tc();
    }
    return 0;
}
