#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int fv = v[f - 1];
        sort(v.begin(), v.end(), greater<int>());

        bool defrmv = true;
        bool defnrmv = true;

 for(int i = 0; i < k; i++) {
            if (v[i] == fv) {
                defrmv = false;
            }
        }
        for(int i = k; i < n; i++) {
            if (v[i] == fv) {
                defnrmv = false;
            }
        }

        if (defnrmv) {
            cout << "YES" << endl;
        } else if (defrmv) {
            cout << "NO" << endl;
        } else {
            cout << "MAYBE" << endl;
        }
    }

    return 0;
}
