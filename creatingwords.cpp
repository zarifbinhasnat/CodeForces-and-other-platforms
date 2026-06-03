#include<bits/stdc++.h>
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
        string a, b;
        cin >> a >> b;
        
        // Swap the first characters of a and b
        swap(a[0], b[0]);
        
        cout << a << " " << b << endl;
    }

    return 0;
}
