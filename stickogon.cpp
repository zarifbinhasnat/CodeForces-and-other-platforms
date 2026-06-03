#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t; // Read the number of test cases
    while(t--) {
        int n;
        cin >> n; // Read the size of the vector
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i]; // Read the elements of the vector
        }
        int ans = 0;
        sort(v.begin(), v.end()); // Sort the vector (O(nlogn)
        for(int i = 0; i < n - 2; i++) {
            if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) {
                // Erase three equal items from the vector v if they exist
                v.erase(v.begin() + i, v.begin() + i + 3);
                ans++;
                n -= 3; // Update the size of the vector
                i--; // Move back one step since we removed three elements
            }
        }
        cout << ans << endl;
    }
    return 0;
}
