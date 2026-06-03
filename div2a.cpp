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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if (v[0] % 2 == 0 && v[n - 1] % 2 == 0)
            cout << 0 << endl;
        else if (v[0] % 2 != 0 && v[n - 1] % 2 != 0)
            cout << 0 << endl;
else{int leftremoval = 1;
for (int i = 1; i < n; i++) {
    if (v[i] % 2 == v[0] % 2)
        leftremoval++;
        else break;
  
}

int rightremoval = 1;
for (int i = n - 2; i >= 0; i--) {
    if (v[i] % 2 == v[n - 1] % 2)
        rightremoval++;
        else break;
   
}
cout << min(leftremoval, rightremoval) << endl;
    }
    }

    return 0;
}
