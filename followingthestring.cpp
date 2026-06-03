#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int l;
        cin >> l;
        vector<int> v(l);

        for (int i = 0; i < l; i++) {
            cin >> v[i];
        }

        string s(l, 'a'); // Initialize string with all 'a's

        // Find the maximum value in the trace array
        int max_val = *max_element(v.begin(), v.end());

        // Counters for each character
        vector<int> count(max_val + 1, 0);

        // Iterate over the trace array
        for (int i = 0; i < l; i++) {
            s[i] = 'a' + count[v[i]]; // Assign character based on count
            count[v[i]]++; // Increment count for the current value in trace array
        }

        cout << s << endl;
    }

    return 0;
}

