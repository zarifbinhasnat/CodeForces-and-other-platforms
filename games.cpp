#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i].first == v[j].second ) {
                cnt++;
            }
            if( v[i].second == v[j].first)
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
