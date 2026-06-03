#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        vector<int> v;
        //write a code to take input from the user


        
        int x;
        cin >> x;
        for (int i = 1; i <= x; i++) {
            v.push_back(i);
        }

        while (v.size() > 1) {
            sort(v.begin(), v.end(), greater<int>());

            if (v.size() >= 2) {
                int largest1 = v[0];
                int largest2 = v[1];

                int result = largest1 + largest2 + largest1 * largest2;

                v.pop_back();  
                v.pop_back();  

                v.push_back(result);
            }
        }
          const int MOD = 1e9 + 7;
  
if (!v.empty()) {
    long long finalResult = v[0] % MOD;
    cout <<finalResult << endl;
    }
    }
    
    return 0;
}