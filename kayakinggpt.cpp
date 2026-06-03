#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int size = 2 * n;
    vector<int> v(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int min_diff = INT_MAX;
    // Try removing every possible pair (i, j) as the two singles
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            vector<int> temp;
            for (int k = 0; k < size; ++k) {
                if (k != i && k != j)
                    temp.push_back(v[k]);
            }
            int sum = 0;
            for (int k = 0; k < temp.size(); k += 2) {
                sum += temp[k + 1] - temp[k];
            }
            min_diff = min(min_diff, sum);
        }
    }
    cout << min_diff << "\n";
    return 0;
}