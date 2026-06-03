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
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a,a+n);
        int ans = a[n-1] + a[n-2];
        cout<<ans<<endl;
    }


    return 0;
}
