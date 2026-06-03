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
        long long n;
        cin >> n;
        vector<long long> a(n+1), dp(n+1), dpp(n+1);
        
        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        dp[0] = 0;
        dpp[0] = 0;
        
        for (long long i = 1; i <= n; i++) {
            if (a[i] >= 0) {
                dpp[i] = dpp[i-1] + a[i];
                dp[i] = max(dp[i-1] + a[i], abs(dpp[i-1] + a[i]));
            } else {
                dpp[i] = dpp[i-1] + a[i];
                dp[i] = max(dp[i-1] + a[i], abs(dpp[i-1] + a[i]));
            }
        }
        
        cout << dp[n] << endl;
    }

    return 0;
}
