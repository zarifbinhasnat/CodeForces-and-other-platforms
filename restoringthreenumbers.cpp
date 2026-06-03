#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int maxNum = max(a, max(b, max(c, d)));
    if (maxNum == a) {
        cout << maxNum - b << " " << maxNum - c << " " << maxNum - d;
    } else if (maxNum == b) {
        cout << maxNum - a << " " << maxNum - c << " " << maxNum - d;
    } else if (maxNum == c) {
        cout << maxNum - a << " " << maxNum - b << " " << maxNum - d;
    } else {
        cout << maxNum - a << " " << maxNum - b << " " << maxNum - c;
    }


    return 0;
}
