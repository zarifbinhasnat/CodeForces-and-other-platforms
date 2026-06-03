#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve ()
{
    lln ,cnt = 0;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    
    }
    sort(a.begin(), a.end());
    ll median = a[n / 2];
     for (ll i = 0; i < n; i++) {
        if (arr[i] == median)
            cnt++;

     }
     cout <<cnt <<endl;
}

}
int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin<<t;
    while(t--)
    {
        solve();
    }


    return 0;
}
