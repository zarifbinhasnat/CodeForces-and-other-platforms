#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    v[i][j] = '#';
                }
            }
            else if (i % 3 == 0)
            {g
                for (int j = 0; j < n; j++)
                {
                    v[i][j] = '.';
                }
                v[i][0] = '#';
            }
            else 
            {
                for (int j = 0; j < n; j++)
                {
                    v[i][j] = '.';
                }
                v[i][n-1] = '#';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}
