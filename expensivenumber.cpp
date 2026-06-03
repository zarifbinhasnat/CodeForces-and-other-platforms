#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        bool ok = false;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
            {
                ok = true;
            }
            else if (ok)
            {
                cnt++;
            }
        }
        cout << n - (cnt + 1) << endl;
    }
}