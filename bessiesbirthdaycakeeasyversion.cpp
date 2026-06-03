#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,x,y;
        cin >> n >> x >> y;
        int s[x];
        for (int i = 0; i < x; i++) {
            cin >> s[i];
        }
        sort(s,s+x);
        int ans =x-2;
        for(int i=0;i<x-1;i++)
        {
            if (s[i]+2==s[i+1])
        {
            ans++;
        }
        }
        if(x>=2 && (s[x-1]+2)%n==s[0])
        {
            ans++;
        }
cout<<ans<<endl;
    }



    return 0;
}
