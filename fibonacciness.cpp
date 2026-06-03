#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> fib(5);
        for (int i = 0; i < 5; i++) {
            if (i != 2) cin >> fib[i];
        }

        int max_fibonacciness = 0;
        vector<int> possible_a3 = {fib[3] - fib[1], fib[4] - fib[3]};

        for (int a3 : possible_a3) {
            fib[2] = a3;
            int count = 0;
            if (fib[2] == fib[0] + fib[1]) count++;
            if (fib[3] == fib[1] + fib[2]) count++;
            if (fib[4] == fib[2] + fib[3]) count++;
            max_fibonacciness = max(max_fibonacciness, count);
        }

        cout << max_fibonacciness << "\n";
    }

    return 0;
}
