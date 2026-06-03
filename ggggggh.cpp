#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int s = 0;
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        s += val;

        // If the partial sum at some moment is equal to k, then the answer to the problem is k.
        if (s == k) {
            std::cout << k << std::endl;
            return 0;
        }
    }

    // Otherwise, print the answer k – 1, that can always be achieved.
    std::cout << k - 1 << std::endl;

    return 0;
}


    return 0;
}
