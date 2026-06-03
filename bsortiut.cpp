#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    

    int n, a, b, sum = 0;
    cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < n; i += 3) {
        if (i + 2 < n) {
            sort(ar + i, ar + i + 3);
            sum += ar[i + 1];
        }
    }

    cout << sum << endl;

    return 0;
}


