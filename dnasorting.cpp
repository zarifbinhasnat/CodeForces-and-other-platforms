#include <bits/stdc++.h>
using namespace std;

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

        int n, m;

        cin >> n >> m;
        map<string, int> mp;
        for (int i = 0; i < m; i++)
        {
            string s;
            cin >> s;
            mp[s] = 0;
        }
        for (auto &x : mp)
        {
            string s = x.first;
            int cnt = 0;
            for (int i = 0; i < s.size(); i++)
            {
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (s[i] > s[j])
                    {
                        cnt++;
                    }
                }
            }
            x.second = cnt;
        }
// sort based on the second element of the pair in ascenfing order
        vector<pair<string, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             { return a.second < b.second; });
       
        // print the sorted vector
        for (auto &x : v)
        {
            cout << x.first << " "<< endl;
        }
    }

    return 0;
}
