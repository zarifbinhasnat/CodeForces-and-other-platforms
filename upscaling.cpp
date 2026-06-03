#include<bits/stdc++.h>
using namespace std;

int main() {
   
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        char a[2*n][2*n];
        for(int i = 0; i < 2 * n; i++) {
            for(int j = 0; j < 2 * n; j++) {
                if((i % 4 == 0 || i % 4 == 1) && (j % 4 == 2 || j % 4 == 3)) {
                    a[i][j] = '.';
                }
                else if((i % 4 == 2 || i % 4 == 3) && (j % 4 == 0 || j % 4 == 1)) {
                    a[i][j] = '.';
                }
                else {
                    a[i][j] = '#';
                }
            }
        }
        for(int i = 0; i < 2 * n; i++) {
            for(int j = 0; j < 2 * n; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
