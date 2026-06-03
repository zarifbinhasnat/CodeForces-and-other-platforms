#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while (t--) {
        int n, h;
        cin >> n >> h;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if (n > h) {
            cout << 1 << endl;
            continue; 
        }
        long long int low = 1, high = 1e18;
        while (low <= high) {
            long long int mid = (low + high) / 2;
            long long int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ceil((double)v[i] / mid); 
            }
            if (sum <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << low << endl;
    }
    return 0;
}
