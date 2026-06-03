#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        sort(ar, ar + n, greater<int>());
        int sum = 0;
        int cnt = 0;
        for (int i = 0; sum <= x; i++)
        {
            sum += ar[i];
            cnt++;
        }
        if (sum > x)
        {
            
            cout << cnt << endl;
        }
        else   cout<<-1<<endl;
    }
    return 0;
}
