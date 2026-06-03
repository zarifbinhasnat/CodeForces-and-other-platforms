#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int l = 0, h = n - 1;
    int ans = 0;
    while (h >= l)
    {
        if (p[l] + p[h] <= x)
        {
            ans++;
            l++;
            h--;
        }
        else{
            ans++;
        h--;}
    }
    cout << ans << endl;

    return 0;
}
