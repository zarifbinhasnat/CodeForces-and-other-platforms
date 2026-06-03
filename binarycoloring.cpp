#include <bits/stdc++.h>
using namespace std;
unsigned int nextPowerOf2(unsigned int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << 31 << endl;
        for (int i = 0; i < 31; i++)
        {
            if (x % 2)
            {
                if (x % 4 == 3)
                {
                    cout << -1 << ' ';
                    x++;
                }
                else
                    cout << 1 << ' ';
            }
            else
                cout << 0 << ' ';
            x /= 2;
            cout << endl;
        }

        return 0;
    }
}
