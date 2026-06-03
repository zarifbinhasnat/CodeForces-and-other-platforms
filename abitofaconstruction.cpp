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
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(n == 1) {
            cout << k << endl;
        } else {

int p = 1 << static_cast<int>(log2(k));
            vector<int> v(n);
            v[0] = p - 1;
            v[1] = k - p + 1;
            for(int i = 2; i < n - 1; i++) {
                v[i] = 0;
            }
            for(int i = 0; i < n - 1; i++) {
                cout << v[i] << " ";
            }
            cout << v[n - 1] << endl;
        }
    }

    return 0;
}
