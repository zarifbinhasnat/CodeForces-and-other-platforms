#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            {
                if (mp[a[i]] > 1)
                {
                    ans++;
                    mp[a[i]] -= 2;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
