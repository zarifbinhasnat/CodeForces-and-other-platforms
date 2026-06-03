#include <bits/stdc++.h>
using namespace std;
string generateString(int n, int k) {
    // If n is less than or equal to k, we just need to repeat the first n letters
    if (n <= k) {
        string s;
        for (int i = 0; i < n; ++i) {
            s += 'a' + i;
        }
        return s;
    }
    
    // Calculate the number of repetitions needed for the first k alphabets
    int repetitions = (n + k - 1) / k;
    // Construct the initial part of the string
    string s;
    for (int i = 0; i < repetitions * k; ++i) {
        s += 'a' + (i % k);
    }
    // Append additional characters to cover all possible subsequences
    for (char i = 'a'; i < 'a' + k; ++i) {
        for (char j = i + 1; j < 'a' + k; ++j) {
            s += i;
            s += j;
        }
    }
    // Return the substring of length n
    return s.substr(0, n);
}

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << generateString(n, k) << endl;
    }
    return 0;
}
