#include <bits/stdc++.h>
using namespace std;

bool square(long long x) {
    long long l = 0;
    long long h = 1e9;
    long long mid;
    while (l <= h) {
        mid = (l + h) / 2;
        if (mid * mid == x)
            return true;
        else if (mid * mid < x)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        long long sum = 0; // Initialize sum here if needed
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i]; // Accumulate sum of elements
        }
        if (square(sum))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
