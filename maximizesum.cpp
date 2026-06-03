#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        sort(ar.begin(), ar.end()); // Sort in non-decreasing order
        long long sum = 0; // Use long long to handle large sums
        for (int i = 1; i < n; i++) {
            sum += (ar[i] + ar[i - 1]);
        }
        cout << sum << endl;
    }

    return 0;
}