#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int sum = 0;
    sort(ar.begin(), ar.end(), greater<int>());

    for (int i = 1; i < n / 3; i += 2) {
        sum += ar[i];
    }

    cout << sum;

    return 0;
}

