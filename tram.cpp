#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    int max_diff = 0;
    for(int i = 1; i < n; i++) {
        int diff = abs(v[i - 1].second - v[i].first) + v[i].second;
        if(diff > max_diff)
            max_diff = diff;
    }
    cout << max_diff << endl;

    return 0;
}

