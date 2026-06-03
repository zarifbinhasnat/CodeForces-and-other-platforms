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
        string s;
        cin >> s;

        // Frequency count of each difficulty level from 'A' to 'G'
        vector<int> freq(7, 0);
        for (char c : s) {
            freq[c - 'A']++;
        }

        int needed_problems = 0;
        // Calculate additional problems needed for each difficulty level
        for (int i = 0; i < 7; i++) {
            if (freq[i] < m) {
                needed_problems += (m - freq[i]);
            }
        }

        cout << needed_problems << endl;
    }

    return 0;
}
