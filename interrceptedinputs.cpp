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
        int k;
        cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int closest_product = INT_MIN;
        int min_diff = INT_MAX;
        int element1 , element2 ;

        int left = 0, right = k - 1;
        while (left < right) {
            int product = v[left] * v[right];
            if (product <= k - 2) {
                int diff = (k - 2) - product;
                if (diff < min_diff) {
                    min_diff = diff;
                    closest_product = product;
                    element1 = v[left];
                    element2 = v[right];
                }
                left++;
            } else {
                right--;
            }
        }

       cout<<element1<<" "<<element2<<endl;
    }

    return 0;
}