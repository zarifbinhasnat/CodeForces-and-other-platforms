#include<bits/stdc++.h>
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
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        string a, b;
        cin >> a >> b;
        
        int last_matched = -1;
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            if (b[i] == a[last_matched + 1]) {
                last_matched++;
                if (last_matched == n - 1)
                    break;
            }
        }
        
        ans = last_matched + 1;
        cout << ans << endl;
    }




    return 0;
}
