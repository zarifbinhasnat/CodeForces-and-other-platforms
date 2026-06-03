#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if a substring s[start:start+length-1] has at most one different character
bool checkSubstring(const string& s, int start, int length) {
    char c = s[start];
    for (int i = start; i < start + length; ++i) {
        if (s[i] != c) {
            // At least two different characters found
            if (i - start > 1) return false;
            c = s[i]; // Update c to the new character
        }
    }
    return true;
}

// Function to find the length of the shortest string k satisfying the constraints
int shortestString(const string& s) {
    int n = s.size();
    // Find all divisors of n
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    // Check each divisor
    int minLength = n;
    for (int d : divisors) {
        bool valid = true;
        for (int i = 0; i < n; i += d) {
            if (!checkSubstring(s, i, d)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            minLength = min(minLength, d);
        }
    }
    return minLength;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << shortestString(s) << endl;
    }
    return 0;
}
