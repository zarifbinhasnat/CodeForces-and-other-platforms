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
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        int ans = abs(s[0] - 1) + abs(s[1] - s[0])+abs(s[2]-s[1]) + abs(s[3] - s[2]) ;
        cout<<ans<<endl;
    }


    return 0;
}
