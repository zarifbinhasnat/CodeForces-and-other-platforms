#include<bits/stdc++.h>
using namespace std;
int main() {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
      int i, j, k;
    int n, m;

    double H, L;
    cin >> H >> L;

    cout << fixed << setprecision(10) << ((L * L - H * H) / (2 * H));

    return 0;
}