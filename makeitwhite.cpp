#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while(t--) {
        int l;
        cin >> l;
        string s;
        cin >> s;
        int b = -1, c = -1; // Initialize with default values
        for (int i = 0; i < l; i++) {
            if (s[i] == 'B') {
                b = i;
                break;
            }
        }
        for(int i = l - 1; i >= 0; i--) {
            if (s[i] == 'B') {
                c = i;
                break;
            }
        }
        int ans = c-b;
        cout << ans+1 << endl;
    }
    return 0;
}
