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

        int ar[2][n];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ar[i][j];
            }
        }
        // a custom sort function to sort based on whether the first row is greater or not
        // then sort
        for (int i = 0; i < n; i++)
        {
            if (ar[0][i] > ar[1][i])
            {
                int temp = ar[0][i];
                ar[0][i] = ar[1][i];
                ar[1][i] = temp;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ar[0][i] > ar[1][i])
                ans += ar[0][i];
            else{
                ans += ar[0][i];
            ans += ar[1][i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}