#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; // Declare variable n
    cin >> n; // Read the size of the array

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the elements of the array
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] == i + 1) { 
                cout << j + 1 << " "; 
                break;
            }
        }
    }
    return 0;
}
