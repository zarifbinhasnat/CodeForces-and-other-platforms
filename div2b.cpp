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
        string s;
        cin >> s;
        int balance = 0, outermost = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                if (balance == 0)
                    outermost++;
                balance++;
            }
            else
            {
                balance--;
            }
        }
        if (outermost > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}