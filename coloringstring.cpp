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
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        if(a[0] == a[n-1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            string s(n, ' ');
            s[0] = 'R';
            s[n-1] = 'B';
            
            for(int i = 1; i < n-1; ++i) {
                if (a[i] == a[0]) {
                    s[i] = 'R';
                } else {
                    s[i] = 'B';
                }
            }
            
            cout << s << '\n';
        }
    }

    return 0;
}
