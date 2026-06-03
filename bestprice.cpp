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
        vector<int >a(n);
        vector<int >b(n);
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i =0;i<n;i++)
        {
            cin>>b[i];
        }
    }
 return 0;
}
