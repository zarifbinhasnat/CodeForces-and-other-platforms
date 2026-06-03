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
        int m, n;
        cin >> m >> n;
        vector<vector<char>> a(m, vector<char>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        int hc = 0, vc = 0;
        int hc_index = -1, vc_index = -1;

        // Calculate maximum horizontal count and the row index
        for (int i = 0; i < m; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '#') {
                    c++;
                }
            }
            if (c > hc) {
                hc = c;
                hc_index = i;
            }
        }

        // Calculate maximum vertical count and the column index
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < m; j++) {
                if (a[j][i] == '#') {
                    c++;
                }
            }
            if (c > vc) {
                vc = c;
                vc_index = i;
            }
        }

       cout<<hc_index+1<<" "<<vc_index+1<<endl;
    }

    return 0;
}
