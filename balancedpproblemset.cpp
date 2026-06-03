#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, n;
        cin >> x >> n;
        if (x == n) {
            cout << 1 << endl;
        } 
        else if (x > n) {
            int part = x / n;
            int remainder = x % n;
            int result = gcd(part, remainder);
            if (result > 1) {
                cout << result << endl;
            } 
            else {
                cout << "Cannot maximize gcd" << endl;
            }
        }
    }
    return 0;
}
