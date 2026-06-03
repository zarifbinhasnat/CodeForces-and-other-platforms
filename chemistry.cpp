#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        map<char, int> m;
        for(int i = 0; i < n; ++i) ++m[s[i]];
        int diff = 0;
        for(auto i: m) {
            if(i.second % 2) ++diff; // Corrected line
        }
        --diff;
        cout << (diff <= k ? "YES" : "NO") << endl; // Corrected line
    }

    return 0;
}

