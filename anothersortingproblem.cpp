#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        long long k = 0;

        for (int i = 0; i + 1 < n; i++)
        {
            if (v[i] > v[i + 1])
            {
                k = max(k, v[i] - v[i + 1]);
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (v[i - 1] > v[i])
            {
                v[i] += k;
            }
        }

        if (is_sorted(v.begin(), v.end()))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}