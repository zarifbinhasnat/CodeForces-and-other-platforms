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
     string s;
     cin>> s;   
     vector<int> cnt(2, 0);
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] - '0']++;//cnt of 1s and 0s
        }
        
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || cnt[1 - (s[i] - '0')] == 0) {
                cout << s.length() - i << endl;
                break;
            }
            cnt[1 - (s[i] - '0')]--;
        }
    }

    return 0;
}
