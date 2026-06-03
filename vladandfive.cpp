#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while (t--) {
        int cnt1=0, cnt2=0;
        char str[6]; // Increase size to accommodate null terminator
        cin >> str;
        for (int i = 0; i < 5; i++) {
            if (str[i] == 'A')
                cnt1++;
            else
                cnt2++;
        }
        if (cnt1 > cnt2)
            cout << 'A' << endl;
        else 
            cout << 'B' << endl;
    }
}
