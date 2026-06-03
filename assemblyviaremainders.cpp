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
       int n;
        cin >> n;
        
        vector<int> x(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> x[i];
        }
        vector<int
       
        a[0] = 1;

        
        int a1 = 1;
        cout << a1 << " ";
        
        for (int i = 1; i < n; ++i) {
            a[i]=a[i-1]+x[i-1];
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        
        cout << endl;

    }
    


    return 0;
}
