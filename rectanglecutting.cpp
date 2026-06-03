#include <iostream>

using namespace std;

// Function to check if it's possible to obtain another rectangle
bool can_obtain_rectangle(int a, int b) {
    // If either of the dimensions is even, it's possible
    return a % 2 == 0 || b % 2 == 0;
    //and also if the half of the dimensions is even, it's possible
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // Read the number of test cases
    int t;
    cin >> t;

    // Iterate through each test case
    for (int i = 0; i < t; ++i) {
        // Read the dimensions of Bob's rectangle
        int a, b;
        cin >> a >> b;

        // Check if it's possible to obtain another rectangle
        if (can_obtain_rectangle(a, b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
