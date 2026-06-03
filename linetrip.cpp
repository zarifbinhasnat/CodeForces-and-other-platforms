#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n+1];
        a[0] = 0; // Fixed array index
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            a[i] = a[i] - a[i - 1]; // Corrected array name
        }
        {
        for(int i=0;i<=n;i++)
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
        }

    return 0;
}
