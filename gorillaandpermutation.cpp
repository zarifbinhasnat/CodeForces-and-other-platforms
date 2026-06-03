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
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> a(n);
        int value =n;
        for(int i=0;i<n;i++) {
            if(value>=0)
            {
                a[i]=value--;
            }
        }
        for (int i = 0; i < n; ++i) {
            if(a[i] == 0) {
                a[i] = value--;
            }
        }
        for(int i=0;i<n;i++)
        
        {
            cout<<a[i]<<" ";}
        cout<<endl;


    }


    return 0;
}
