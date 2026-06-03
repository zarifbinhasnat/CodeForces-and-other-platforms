#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> alphabetCounts(26, 0); // Initialize vector with 26 elements, all initialized to 0

        for (char c : s) {
          
                alphabetCounts[c - 'A']++; // Increment count in corresponding index of the vector
            
        }

        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(alphabetCounts[i] > i) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
