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
    int n,k;
    cin>>n>>k;
    vector<int> l(n);
    vector<int> r(n);
    for (int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for (int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    vector<int> a(n),b(n);
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        a[i]=max(l[i],r[i]);
        b[i]=min(l[i],r[i]);
        ans+=a[i];
    }
    sort(b.begin(),b.end(),greater<int>());
    for (int i=0;i<(k-1);i++)
    {
        ans+=b[i];
    }
        cout<<ans+1<<endl;
    }

    return 0;
}
