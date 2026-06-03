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
        set<int> a, b, c;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            b.insert(y);
        }

        if (a.size() +b.size() >= 4)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
