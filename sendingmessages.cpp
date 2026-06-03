#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t;
    cin >> t;
    while(t--) {
        long long n, f, a, b;
        cin >> n >> f >> a >> b;
        int ar[n+1 ];
        ar[0]=0;
        
        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
        }
        
        for (int i = 1; i < (n+1); i++) {
                    f-=min((ar[i] - ar[i - 1]) * a,b);
        }
            
        if (f > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
