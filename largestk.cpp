#include<bits/stdc++.h>
using namespace std;

// Function to find the largest integer K
int largest_K(int X, int Y) {
    return (Y / (X + 1));
}

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t; // Input number of test cases
    while (t--) {
        int X, Y;
        cin >> X >> Y; // Input X and Y
        cout << largest_K(X, Y) << endl;
    }
    return 0;
}
