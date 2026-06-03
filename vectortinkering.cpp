#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
      vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, -3},
        {2, 3, 2},
        {3, 1, 1},
        {1, 4, 2}
    };
for (int val : edges[0]) {
    cout << val << " ";
}
cout << endl;

    return 0;
}
