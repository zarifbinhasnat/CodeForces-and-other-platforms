#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> freq;

    for (ll &x : arr) {
        cin >> x;
        freq[x]++;
    }

    ll legs = -1;
    for (auto &[val, count] : freq) {
        if (count >= 2) legs = max(legs, val);
    }

    if (legs == -1) {
        cout << "-1\n";
        return;
    }

    vector<ll> nw;
    int removed = 0;
    for (ll x : arr) {
        if (x == legs && removed < 2) {
            removed++;
        } else {
            nw.push_back(x);
        }
    }

    sort(nw.begin(), nw.end());

    for (size_t i = 0; i < nw.size(); i++) {
        ll target = nw[i] - 2 * legs;
        auto lwr = upper_bound(nw.begin(), nw.end(), target);
        
        if (lwr != nw.end() && *lwr <= nw[i] && lwr - nw.begin() != (ll)i) {
            cout << legs << " " << legs << " " << *lwr << " " << nw[i] << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    while (T--) solve();

    return 0;
}
