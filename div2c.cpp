#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> d(n);
        for (int i = 0; i < n; i++) cin >> d[i];

        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

        int minH = 0, maxH = 0;
        vector<int> h(n + 1);
        bool possible = true;

        for (int i = 0; i < n; i++) {
            int newMin = 1e9, newMax = -1e9;
            if (d[i] == 0) {
                newMin = minH;
                newMax = maxH;
            } else if (d[i] == 1) {
                newMin = minH + 1;
                newMax = maxH + 1;
            } else {
                // unknown, try both 0 and 1
                newMin = min(minH, minH + 1);
                newMax = max(maxH, maxH + 1);
            }

            // intersect with obstacle constraints
            newMin = max(newMin, l[i]);
            newMax = min(newMax, r[i]);

            if (newMin > newMax) {
                possible = false;
                break;
            }

            minH = newMin;
            maxH = newMax;
        }

        if (!possible) {
            cout << -1 << '\n';
            continue;
        }

        // reconstruct one valid `d` from back to front
        vector<int> result(n);
        int h = minHs[n]; // choose any value within final valid height range
        for (int i = n - 1; i >= 0; i--) {
            if (d[i] != -1) {
                if (d[i] == 1) {
                    if (h - 1 >= minHs[i] && h - 1 <= maxHs[i]) {
                        result[i] = 1;
                        h -= 1;
                    } else {
                        possible = false;
                        break;
                    }
                } else {
                    if (h >= minHs[i] && h <= maxHs[i]) {
                        result[i] = 0;
                        // h stays the same
                    } else {
                        possible = false;
                        break;
                    }
                }
            } else {
                // try 1 first (greedy height drop)
                if (h - 1 >= minHs[i] && h - 1 <= maxHs[i] && h - 1 >= l[i] && h - 1 <= r[i]) {
                    result[i] = 1;
                    h -= 1;
                } else if (h >= minHs[i] && h <= maxHs[i] && h >= l[i] && h <= r[i]) {
                    result[i] = 0;
                    // h stays the same
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (!possible || h != 0) {
            cout << -1 << '\n';
        } else {
            for (int x : result) cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}
