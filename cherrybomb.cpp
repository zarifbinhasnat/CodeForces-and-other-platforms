#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        ll x = -1;
        bool conflict = false;
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                if (x == -1) {
                    x = a[i] + b[i];
                } else {
                    if (x != a[i] + b[i]) {
                        conflict = true;
                        break;
                    }
                }
            }
        }
        
        if (conflict) {
            cout << 0 << "\n";
            continue;
        }
        
        if (x != -1) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    ll needed = x - a[i];
                    if (needed < 0 || needed > k) {
                        ok = false;
                        break;
                    }
                }
            }
            cout << (ok ? 1 : 0) << "\n";
        } else {
            ll max_a = *max_element(a.begin(), a.end());
            ll min_a = *min_element(a.begin(), a.end());
            
            ll low = max_a;
            ll high = min_a + k;
            
            if (low > high) {
                cout << 0 << "\n";
            } else {
                cout << (high - low + 1) << "\n";
            }
        }
    }
    return 0;
}
