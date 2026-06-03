#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == k) {
            long long x = 1, f = 0;
            for (int i = 2; i <= n; i += 2) {
                if (a[i - 1] != x) {
                    f = 1;
                    cout << x << endl;
                    break;
                }
                x++;
            }
            if (f == 0) {
                cout << k / 2 + 1 << endl;
            }
            continue;
        }

        long long need = (n - k);
        need += 2;
        int f = 0;
        for (int i = 2; i <= need; i++) {
            if (a[i - 1] != 1) {
                f = 1;
                break;
            }
        }
        if (f) {
            cout << "1" << endl;
        } else {
            cout << "2" << endl;
        }
    }
    return 0;
}