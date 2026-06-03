#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n == k) {
            for (int i = 0; i < n; i++) {
                cout << "1 ";
            }
            cout << endl;
        }
        else if (k == 1) {
            for (int i = 0; i < n; i++) {
                cout << i +1<< " ";
            }
            cout << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
