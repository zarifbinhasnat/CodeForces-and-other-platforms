#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define ppb pop_back
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define all(x) x.begin(),x.end()

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n; 
        cin >> n;
        n = n - n % 10 + (n % 10 + 1) % 10;
        while (n > 9) {
            if (n % 10 == 0) {
                cout << "NO\n";
                break;
            }
            n /= 10;
        }
        if (n <= 9) {
            cout << (n == 1 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}