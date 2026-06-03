#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
vector<int> pow2 = {1};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n), q(n), pos_p(n), pos_q(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            pos_p[p[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            cin >> q[i];
            pos_q[q[i]] = i;
        }

        if ((int)pow2.size() <= n) {
            int old_size = pow2.size();
            pow2.resize(n + 1);
            for (int i = old_size; i <= n; ++i) {
                pow2[i] = (1LL * pow2[i - 1] * 2) % MOD;
            }
        }

        vector<int> max_p(n), max_q(n);
        max_p[0] = p[0];
        max_q[0] = q[0];
        for (int i = 1; i < n; ++i) {
            max_p[i] = max(max_p[i - 1], p[i]);
            max_q[i] = max(max_q[i - 1], q[i]);
        }

        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            int s = -1;

            if (max_p[i] > max_q[i]) {
                int j = pos_p[max_q[i]];
                int k = i - j;
                if (k >= 0 && k < n) {
                    s = q[k];
                }
            }
            else if (max_p[i] < max_q[i]) {
                int j = pos_q[max_p[i]];
                int k = i - j;
                if (k >= 0 && k < n) {
                    s = p[k];
                }
            }
            else {
                int e = max_p[i];
                int j1 = pos_p[e], j2 = pos_q[e];
                int k1 = i - j1, k2 = i - j2;
                int s1 = (k1 >= 0 && k1 < n && q[k1] != -1) ? q[k1] : -1;
                int s2 = (k2 >= 0 && k2 < n && p[k2] != -1) ? p[k2] : -1;
                s = max(s1, s2);
            }

            int val = (1LL * pow2[max_p[i]] + pow2[s]) % MOD;
            r[i] = val;
        }

        for (int i = 0; i < n; ++i) {
            cout << r[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}
