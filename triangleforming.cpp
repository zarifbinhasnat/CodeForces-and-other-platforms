#include<bits/stdc++.h>
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
            int a;
            cin >> a;
            ar[i] = pow(2, a); 
        }

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if ((ar[i - 2] + ar[i - 1]) > ar[i])
                cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
