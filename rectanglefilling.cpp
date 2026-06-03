#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> gr(n); // Using vector of strings to store the grid

        for (int i = 0; i < n; i++) {
            cin >> gr[i];
        }

        string ans = "YES";

        if (gr[0][0] != gr[n - 1][m - 1]) {
            bool impossible = true;

            // Check if top row has the same characters
            for (int j = 0; j < m - 1; j++) {
                if (gr[0][j] != gr[0][j + 1] || gr[n - 1][j] != gr[n - 1][j + 1]) {
                    impossible = false;
                    break;
                }
            }
            if (impossible) {
                ans = "NO";
            }

            impossible = true;

            // Check if left column has the same characters
            for (int i = 0; i < n - 1; i++) {
                if (gr[i][0] != gr[i + 1][0] || gr[i][m - 1] != gr[i + 1][m - 1]) {
                    impossible = false;
                    break;
                }
            }

            if (impossible) {
                ans = "NO";
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
