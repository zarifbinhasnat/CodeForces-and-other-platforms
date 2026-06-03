#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<int> v1(m);
        for(int i = 0; i < m; ++i) {
            cin >> v1[i]; // corrected index from v[i] to v1[i]
        }
        vector<int> v2(n+m);

        // Combine and save both arrays in v2
        std::copy(v.begin(), v.end(), v2.begin());
        std::copy(v1.begin(), v1.end(), v2.begin() + n);

        // Create sets for fast lookup
        unordered_set<int> setV(v.begin(), v.end());
        unordered_set<int> setV1(v1.begin(), v1.end());

        vector<int> v3;
        for(int j=0; j<k; j++) {
            v3.push_back(j+1);
        }

        int countV = 0, countV1 = 0;
        for(int num : v3) {
            if(setV.find(num) != setV.end()) {
                countV++;
            }
            if(setV1.find(num) != setV1.end()) {
                countV1++;
            }
        }

        if(countV >= k/2 && countV1 >= k/2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
