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
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        bool found = false;

        for (int i = 0; i < 6; ++i) {
            if (x.find(s) != string::npos) {
                cout << i << endl;
                found = true;
                break;
            }
            x += x; // Concatenate x with itself
        }
        
        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
