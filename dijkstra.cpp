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
    // storing the adj list pairwiseof dorected graph
    vector<vector<pair<int, int>>> adjlist(1000);
    // take matrix input
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjlist[a].emplace_back(make_pair(b, c));
    }

    return 0;
}
