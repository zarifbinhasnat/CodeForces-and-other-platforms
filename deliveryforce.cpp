#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int m = 0;
    for (int i = 0; i < n; i += 3) {
        sort(v.begin() + i, v.begin() + i + 3); // Sorting the subarray
        m += v[i + 1]; // Adding the middle element to the sum
    }
    cout << m << endl;

    return 0;
}
